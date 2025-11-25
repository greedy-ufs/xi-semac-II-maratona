#!/usr/bin/env python3

def main():
    n = int(input())
    if n == 0:
        print("SIM")
        return
    
    soma = 0
    numbers = map(int, input().split())
    for x in numbers:
        soma += x

    if soma % n == 0:
        print("SIM")
    else:
        print("NAO")

if __name__ == '__main__':
    main()