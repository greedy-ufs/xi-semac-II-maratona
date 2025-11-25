#!/usr/bin/env python3

MAXN = 200010

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        v = list(map(int, input().split()))
        
        xr = 0
        for i in range(n):
            xr ^= v[i]
        
        if xr != 0:
            print("Breno")
        else:
            print("Adversario")

if __name__ == '__main__':
    main()