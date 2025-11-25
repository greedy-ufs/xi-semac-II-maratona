#!/usr/bin/env python3

n, a, t = map(int, input().split())
ans = 0
ans += (n // a) * t
n = n % a
if n != 0:
    ans += t
print(ans)
