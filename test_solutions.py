#!/usr/bin/env python3
"""
Script para compilar e testar soluções C++ contra casos de teste
"""

import os
import subprocess
import sys
from pathlib import Path
from typing import List, Tuple, Optional
import tempfile

class Colors:
    """Cores para output no terminal"""
    GREEN = '\033[92m'
    RED = '\033[91m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    RESET = '\033[0m'
    BOLD = '\033[1m'

def compile_cpp(source_file: Path, output_file: Path) -> Tuple[bool, str]:
    """
    Compila um arquivo C++ usando g++
    
    Args:
        source_file: Caminho do arquivo fonte
        output_file: Caminho do executável de saída
    
    Returns:
        Tupla (sucesso, mensagem de erro)
    """
    try:
        cmd = [
            'g++',
            '-x', 'c++',
            '-O2',
            '-std=c++20',
            '-o', str(output_file),
            str(source_file)
        ]
        
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=30
        )
        
        if result.returncode == 0:
            return True, ""
        else:
            return False, result.stderr
            
    except subprocess.TimeoutExpired:
        return False, "Timeout durante compilação"
    except Exception as e:
        return False, f"Erro ao compilar: {str(e)}"

def run_test(executable: Path, input_file: Path, expected_output: Path, 
             timelimit: int = 5) -> Tuple[str, str, float]:
    """
    Executa um teste com um arquivo de entrada e compara com a saída esperada
    
    Args:
        executable: Caminho do executável
        input_file: Arquivo de entrada
        expected_output: Arquivo com saída esperada
        timelimit: Tempo limite em segundos
    
    Returns:
        Tupla (status, mensagem, tempo_execução)
        status pode ser: "AC" (Accepted), "WA" (Wrong Answer), "TLE" (Time Limit), "RE" (Runtime Error)
    """
    try:
        with open(input_file, 'r') as f:
            input_data = f.read()
        
        with open(expected_output, 'r') as f:
            expected = f.read().strip()
        
        # Executa o programa
        result = subprocess.run(
            [str(executable)],
            input=input_data,
            capture_output=True,
            text=True,
            timeout=timelimit
        )
        
        if result.returncode != 0:
            return "RE", f"Runtime Error (código: {result.returncode})", 0.0
        
        output = result.stdout.strip()
        
        # Compara saídas
        if output == expected:
            return "AC", "Accepted", 0.0
        else:
            # Verifica se a diferença é apenas espaços em branco
            if ' '.join(output.split()) == ' '.join(expected.split()):
                return "AC", "Accepted (diferença em espaços)", 0.0
            else:
                return "WA", "Wrong Answer", 0.0
                
    except subprocess.TimeoutExpired:
        return "TLE", f"Time Limit Exceeded (>{timelimit}s)", float(timelimit)
    except Exception as e:
        return "RE", f"Runtime Error: {str(e)}", 0.0

def get_test_cases(problem_dir: Path) -> List[Tuple[Path, Path]]:
    """
    Obtém lista de casos de teste (input, output) para um problema
    
    Args:
        problem_dir: Diretório do problema (ex: A/, B/, etc)
    
    Returns:
        Lista de tuplas (input_file, output_file)
    """
    input_dir = problem_dir / 'input'
    output_dir = problem_dir / 'output'
    
    if not input_dir.exists() or not output_dir.exists():
        return []
    
    test_cases = []
    
    # Lista todos os arquivos de input
    input_files = sorted(input_dir.iterdir())
    
    for input_file in input_files:
        if input_file.is_file():
            # Procura o arquivo de output correspondente
            output_file = output_dir / input_file.name
            if output_file.exists():
                test_cases.append((input_file, output_file))
    
    return test_cases

def test_solution(problem_letter: str, workspace_dir: Path) -> dict:
    """
    Testa uma solução completa
    
    Args:
        problem_letter: Letra do problema (A, B, C, etc)
        workspace_dir: Diretório raiz do workspace
    
    Returns:
        Dicionário com resultados dos testes
    """
    solution_file = workspace_dir / 'solutions' / f'{problem_letter}.cpp'
    problem_dir = workspace_dir / problem_letter
    
    results = {
        'problem': problem_letter,
        'compiled': False,
        'compile_error': '',
        'tests': []
    }
    
    # Verifica se arquivo de solução existe
    if not solution_file.exists():
        results['compile_error'] = f"Arquivo {solution_file} não encontrado"
        return results
    
    # Verifica se diretório do problema existe
    if not problem_dir.exists():
        results['compile_error'] = f"Diretório {problem_dir} não encontrado"
        return results
    
    # Cria diretório temporário para compilação
    with tempfile.TemporaryDirectory() as tmpdir:
        executable = Path(tmpdir) / f'{problem_letter}.exe'
        
        # Compila
        print(f"{Colors.BLUE}Compilando {problem_letter}.cpp...{Colors.RESET}", end=' ')
        success, error = compile_cpp(solution_file, executable)
        
        if not success:
            print(f"{Colors.RED}ERRO{Colors.RESET}")
            results['compile_error'] = error
            return results
        
        print(f"{Colors.GREEN}OK{Colors.RESET}")
        results['compiled'] = True
        
        # Obtém casos de teste
        test_cases = get_test_cases(problem_dir)
        
        if not test_cases:
            print(f"{Colors.YELLOW}Nenhum caso de teste encontrado{Colors.RESET}")
            return results
        
        print(f"Executando {len(test_cases)} casos de teste...")
        
        # Executa cada teste
        for i, (input_file, output_file) in enumerate(test_cases, 1):
            test_name = input_file.name
            status, message, time = run_test(executable, input_file, output_file)
            
            results['tests'].append({
                'name': test_name,
                'status': status,
                'message': message,
                'time': time
            })
            
            # Imprime resultado
            if status == "AC":
                color = Colors.GREEN
                symbol = "✓"
            elif status == "WA":
                color = Colors.RED
                symbol = "✗"
            elif status == "TLE":
                color = Colors.YELLOW
                symbol = "⏱"
            else:  # RE
                color = Colors.RED
                symbol = "!"
            
            print(f"  Teste {i:2d} ({test_name:10s}): {color}{symbol} {status}{Colors.RESET} - {message}")
    
    return results

def print_summary(all_results: List[dict]):
    """Imprime um resumo de todos os resultados"""
    print(f"\n{Colors.BOLD}{'='*60}{Colors.RESET}")
    print(f"{Colors.BOLD}RESUMO{Colors.RESET}")
    print(f"{Colors.BOLD}{'='*60}{Colors.RESET}\n")
    
    for result in all_results:
        problem = result['problem']
        
        if not result['compiled']:
            print(f"Problema {problem}: {Colors.RED}ERRO DE COMPILAÇÃO{Colors.RESET}")
            continue
        
        tests = result['tests']
        if not tests:
            print(f"Problema {problem}: {Colors.YELLOW}SEM TESTES{Colors.RESET}")
            continue
        
        total = len(tests)
        ac_count = sum(1 for t in tests if t['status'] == 'AC')
        
        if ac_count == total:
            status_color = Colors.GREEN
            status_text = "TODOS CORRETOS"
        elif ac_count > 0:
            status_color = Colors.YELLOW
            status_text = f"{ac_count}/{total} CORRETOS"
        else:
            status_color = Colors.RED
            status_text = "NENHUM CORRETO"
        
        print(f"Problema {problem}: {status_color}{status_text}{Colors.RESET}")

def main():
    """Função principal"""
    workspace_dir = Path(__file__).parent
    solutions_dir = workspace_dir / 'solutions'
    
    print(f"{Colors.BOLD}{'='*60}{Colors.RESET}")
    print(f"{Colors.BOLD}Testador de Soluções{Colors.RESET}")
    print(f"{Colors.BOLD}{'='*60}{Colors.RESET}\n")
    
    # Verifica se diretório de soluções existe
    if not solutions_dir.exists():
        print(f"{Colors.RED}Erro: Diretório 'solutions' não encontrado{Colors.RESET}")
        sys.exit(1)
    
    # Lista todas as soluções .cpp
    solution_files = sorted(solutions_dir.glob('*.cpp'))
    
    if not solution_files:
        print(f"{Colors.YELLOW}Nenhuma solução .cpp encontrada em 'solutions'{Colors.RESET}")
        sys.exit(0)
    
    # Se argumentos foram passados, testa apenas esses problemas
    if len(sys.argv) > 1:
        problems_to_test = [arg.upper() for arg in sys.argv[1:]]
    else:
        # Extrai letras dos problemas
        problems_to_test = [f.stem for f in solution_files]
    
    print(f"Problemas a testar: {', '.join(problems_to_test)}\n")
    
    all_results = []
    
    # Testa cada solução
    for problem in problems_to_test:
        print(f"\n{Colors.BOLD}{'─'*60}{Colors.RESET}")
        print(f"{Colors.BOLD}Problema {problem}{Colors.RESET}")
        print(f"{Colors.BOLD}{'─'*60}{Colors.RESET}\n")
        
        result = test_solution(problem, workspace_dir)
        all_results.append(result)
    
    # Imprime resumo
    print_summary(all_results)

if __name__ == '__main__':
    main()
