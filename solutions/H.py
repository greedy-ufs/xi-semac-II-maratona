#!/usr/bin/env python3

def main():
    entrada = list(map(int, input().split()))
    n = entrada[0]
    m = entrada[1]
    k = entrada[2]
    s = int(input())
    ans = 0
    for _ in range(m):
        x = int(input())
        qtd = 0
        for i in range(n):
            bit_x = (x >> i) & 1
            bit_s = (s >> i) & 1
            if bit_x != bit_s:
                qtd += 1
        if qtd <= k:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()