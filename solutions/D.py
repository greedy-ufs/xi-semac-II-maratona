#!/usr/bin/env python3

def main():
    n = int(input())
    v = []
    for _ in range(n):
        a, b = map(int, input().split())
        v.append((a, b))

    v.sort(key=lambda x: x[1])

    temp = 0
    cnt = 0
    for start, end in v:
        if start >= temp:
            cnt += 1
            temp = end

    print(cnt)

if __name__ == '__main__':
    main()