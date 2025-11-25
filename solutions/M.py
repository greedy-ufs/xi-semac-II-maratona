#!/usr/bin/env python3

MAXN = 200010

def main():
    n, t = map(int, input().split())
    k = list(map(int, input().split()))

    k.sort()

    def possible(m):
        prod = 0
        for i in range(n):
            prod += m // k[i]
            if prod >= t:
                return True
        return False

    l = 0
    r = 10**18
    while l < r:
        m = l + (r - l) // 2
        if possible(m):
            r = m
        else:
            l = m + 1

    print(l)

main()