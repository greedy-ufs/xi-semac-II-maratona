#!/usr/bin/env python3

MOD = 10**9 + 7

def fib(n):
    if n == 0 or n == 1:
        return n
    a = 0  # fib(n-2)
    b = 1  # fib(n-1)
    
    for i in range(2, n + 1):
        c = (a + b) % MOD
        a = b
        b = c
    
    return c

def main():
    n = int(input())
    print(fib(n))

if __name__ == '__main__':
    main()