import os
import re
import gzip
import binascii
import sys

# Configurações
ARQUIVO_SQL = './backup/bocadb_20251130_112441.sql'  # Pode ser .sql ou .sql.gz
PASTA_SAIDA = 'codigos'  # Pasta na raiz do projeto

def limpar_nome(nome):
    """Remove caracteres inválidos para nomes de pastas."""
    # Substitui caracteres especiais por underscore e remove espaços extras
    nome = re.sub(r'[\\/*?:"<>|]', '_', nome)
    return nome.strip()

def abrir_arquivo(caminho):
    """Abre arquivo normal ou .gz no modo texto."""
    if caminho.endswith('.gz'):
        return gzip.open(caminho, 'rt', encoding='utf-8', errors='replace')
    else:
        return open(caminho, 'r', encoding='utf-8', errors='replace')

def extrair_tudo():
    if not os.path.exists(ARQUIVO_SQL):
        print(f"Erro: Arquivo '{ARQUIVO_SQL}' não encontrado.")
        return

    print(f"Lendo arquivo: {ARQUIVO_SQL}...")
    
    users = {}          # {usernumber: teamname}
    oid_map = {}        # {oid: list of {path_to_save}}
    
    # Passo 1A: Ler usertable primeiro
    print("Passo 1/3: Mapeando usuários...")
    with abrir_arquivo(ARQUIVO_SQL) as f:
        mode = None
        
        for line in f:
            line = line.strip()
            
            if line.startswith('COPY public.usertable'):
                mode = 'usertable'
                continue
            elif line == r'\.':
                mode = None
                if len(users) > 0:
                    break  # Já lemos a usertable, podemos parar
                continue
            
            if mode == 'usertable':
                parts = line.split('\t')
                if len(parts) > 6:
                    # Estrutura BOCA: contestnumber(0), usersitenumber(1), usernumber(2), 
                    # username(3), userfullname(4), userdesc(5), usertype(6)
                    uid = parts[2]
                    team_name = parts[4] if parts[4].strip() else parts[3]
                    user_type = parts[6]
                    
                    # Apenas times (não admin, staff, etc)
                    if user_type != 'team':
                        continue
                    
                    users[uid] = limpar_nome(team_name)
    
    print(f"-> Encontrados {len(users)} times")
    
    # Passo 1B: Ler runtable
    print("Passo 2/3: Mapeando submissões...")
    with abrir_arquivo(ARQUIVO_SQL) as f:
        mode = None
        
        for line in f:
            line = line.strip()
            
            if line.startswith('COPY public.runtable'):
                mode = 'runtable'
                continue
            elif line == r'\.':
                mode = None
                if len(oid_map) > 0:
                    break  # Já lemos a runtable, podemos parar
                continue
            
            if mode == 'runtable':
                parts = line.split('\t')
                # Estrutura BOCA: contestnumber(0), runsitenumber(1), runnumber(2), 
                # usernumber(3), rundate(4), rundatediff(5), rundatediffans(6), 
                # runproblem(7), runfilename(8), rundata(9)
                if len(parts) > 9:
                    run_id = parts[2]
                    uid = parts[3]
                    problem = parts[7]
                    filename = parts[8]
                    oid = parts[9]
                    
                    if uid in users:
                        team_folder = users[uid]
                        # Cria o caminho: PASTA_SAIDA/Nome_Time/Problema_RunID_Filename
                        save_path = os.path.join(PASTA_SAIDA, team_folder, f"{problem}_{run_id}_{filename}")
                        
                        if oid not in oid_map:
                            oid_map[oid] = []
                        oid_map[oid].append(save_path)

    total_files = sum(len(v) for v in oid_map.values())
    print(f"-> Mapeados {total_files} arquivos para extração")
    
    # Passo 2: Extrair os binários (Large Objects)
    print("Passo 3/3: Extraindo códigos fonte...")
    
    current_oid = None
    extracted_count = 0
    
    # Precisamos reabrir o arquivo para ler do início novamente (segurança contra ordem dos comandos)
    with abrir_arquivo(ARQUIVO_SQL) as f:
        for line in f:
            # Detecta abertura de objeto: lo_open('12345', ...)
            if 'pg_catalog.lo_open' in line:
                match = re.search(r"lo_open\('(\d+)'", line)
                if match:
                    oid = match.group(1)
                    # Só processamos se este OID pertencer a alguma submissão mapeada
                    if oid in oid_map:
                        current_oid = oid
                        # Garante que as pastas existam
                        for path in oid_map[oid]:
                            os.makedirs(os.path.dirname(path), exist_ok=True)
                    else:
                        current_oid = None
            
            # Detecta dados: lowrite(0, '\xDEADBEEF...')
            elif 'pg_catalog.lowrite' in line and current_oid:
                match_data = re.search(r"lowrite\(\d+, '(\\x[0-9a-fA-F]+)'\)", line)
                if match_data:
                    hex_data = match_data.group(1)
                    # Converte hex para bytes
                    try:
                        binary_data = binascii.unhexlify(hex_data[2:])
                        
                        # Escreve em todos os arquivos que referenciam este OID
                        for path in oid_map[current_oid]:
                            with open(path, 'ab') as out_file:
                                out_file.write(binary_data)
                        
                        extracted_count += 1
                        # Feedback visual simples a cada 100 fragmentos
                        if extracted_count % 500 == 0:
                            print(f"   ... processados {extracted_count} fragmentos de dados.")
                            
                    except binascii.Error:
                        print(f"Aviso: Erro ao decodificar dados para OID {current_oid}")

            elif 'pg_catalog.lo_close' in line:
                current_oid = None

    print("\n" + "="*40)
    print(f"Concluído! Arquivos extraídos em: {os.path.abspath(PASTA_SAIDA)}")
    print("="*40)

if __name__ == "__main__":
    # Verifica se o arquivo padrão existe, senão tenta achar versão .gz
    if not os.path.exists(ARQUIVO_SQL) and os.path.exists(ARQUIVO_SQL + ".gz"):
        ARQUIVO_SQL = ARQUIVO_SQL + ".gz"
        
    extrair_tudo()