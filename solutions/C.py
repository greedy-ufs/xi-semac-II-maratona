#!/usr/bin/env python3

def main():
    n = int(input())
    ans = 0
    numbers = map(int, input().split())
    for x in numbers:
        if x == 3:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()