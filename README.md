# II Maratona de Programação - SEMAC

Sistema para gerenciar problemas e submissões da maratona de programação SEMAC utilizando BOCA.

Se você quiser ver as sbumissões, fizemos o backup dos dados, você ver como acessar na pasta [backup](backup/readme.md)

## Índice

- [Visão Geral](#visão-geral)
- [Arquitetura](#arquitetura)
- [Instalação](#instalação)
- [Configuração](#configuração)
- [Referências](#referências)

## Visão Geral

Este projeto utiliza duas máquinas:
- **Máquina 1**: Servidor BOCA (gerenciamento de contest)
- **Máquina 2**: Animeitor (placar em tempo real)

## Arquitetura

### Requisitos de Hardware
- (servidor boca) droplet com 2gb e 1 cpu 
- (Animeitor) droplet com 1gb e 1 cpu


## Instalação

### Máquina 1 - Servidor BOCA

#### Passo 1: Instalar BOCA

```bash
sudo apt-get update
sudo add-apt-repository ppa:icpc-latam/maratona-linux
sudo apt-get update
sudo apt-get install boca -y
boca-createjail
echo "allUsers 1/1/1000" > /var/www/boca/src/private/webcast.sep
```

#### Passo 2: Configurar Apache2

```bash
sudo tee /etc/apache2/sites-available/000-boca.conf > /dev/null <<EOF
<Directory "/var/www/boca/src">
    AllowOverride Options AuthConfig Limit
    Require all granted
    AddDefaultCharset utf-8
</Directory>

<Directory "/var/www/boca/src/private">
    Require all denied
</Directory>

<Directory "/var/www/boca">
    Require all denied
</Directory>

Alias /boca /var/www/boca/src

<Files "webcast.php">
    Require all granted
</Files>
EOF
```

#### Passo 3: Aumentar Limite de Upload

Editar os valores em `/etc/php/8.x/apache2/php.ini` ou `/etc/php/8.3/fpm/php.ini`:

```ini
...
upload_max_filesize = 100M
post_max_size = 100M
max_file_uploads = 20
...
```

Depois é preciso reiniciar o sistema para que tome efeito a alteração
```
sudo systemctl restart php8.3-fpm
sudo systemctl restart apache2
```

### Passo 4: Configuração de score

O arquivo `score.sep` define as permissões de acesso ao placar. Para configurar:

1. Dar permissão de leitura/escrita:
   ```bash
   chmod 644 /var/www/boca/src/private/score.sep
   ```

2. Adicionar as linhas de configuração:
   ```txt
   Global 1 # /^ccl/ /^admin/
   UFS 2000/2999/1 # /^team/ /^score/ /^admin/
   CCL 3000/3999/1 # /^ccl/ /^score/ /^admin/
   ```

### Máquina 2 - Placar (Animeitor)

#### Passo 1: Instalar Docker

```bash
sudo apt-get update
sudo apt-get install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo \
    "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
    $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update
sudo apt install docker-ce
sudo systemctl status docker
```

#### Passo 2: Clonar Repositório do Animeitor

```bash
git clone https://github.com/wuerges/maratona-animeitor-rust
cd maratona-animeitor-rust
```

#### Passo 3: Configurar Arquivo `.env`

Criar arquivo `.env` na raiz do projeto:

```env
# Credenciais para acesso ao Reveleitor
SECRET=./config/basic_secret.toml

# Configuração de locais/sedes
SEDES=./config/basic.toml

# URL do BOCA (substitua {IP_COMPUTADOR1} pelo IP da Máquina 1)
BOCA_URL=http://{IP_COMPUTADOR1}/boca/admin/report/webcast.php?webcastcode=allUsers

# Prefixo da API do Animeitor
PREFIX=http://localhost:8000

# Porta pública de acesso
PUBLIC_PORT=80
```

Colocar a mesma configuração de `maratona-animeitor-rust/client-v2/static/user-styles.css` com o mesmo arquivo em user-styles.css, ao final, subir o docker

```bash
docker compose up -d
```

## Referências

- [BOCA Documentation](https://github.com/gabrielrbernardi/BOCADocumentation)
- [BOCA Docker](https://github.com/joaofazolo/boca-docker)
- [Animeitor (Placar em Tempo Real)](https://github.com/wuerges/maratona-animeitor-rust/)
- [Caderno de Problemas da Maratona](https://docs.google.com/document/d/1gvnBEyPKjA8JPNlUSRVkY3Bu0ruurBE6PxNpCtgwNQc/edit?tab=t.0)
- [Discussão sobre Configuração de Scores](https://groups.google.com/g/boca-users/c/Ndvg6HzYZr8/m/px1G9XN5AQAJ)
