#!/usr/bin/env python3

def main():
    n, x = map(int, input().split())

    pesos = list(map(int, input().split()))
    favs = list(map(int, input().split()))

    dp = [0] * (x + 1)

    for i in range(n):
        p = pesos[i]
        f = favs[i]
        for j in range(x, p - 1, -1):
            dp[j] = max(dp[j], dp[j - p] + f)

    print(dp[x])

if __name__ == '__main__':
    main()