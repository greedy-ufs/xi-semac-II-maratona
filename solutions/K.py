#!/usr/bin/env python3

def main():
    s = input()
    n = int(input())
    for _ in range(n):
        a = input()
        i = 0
        tam_s = len(s)
        for c in a:
            if i < tam_s and c == s[i]:
                i += 1
        if i == tam_s:
            print("MUITO FACIL")
        else:
            print("NAO MUITO FACIL")

if __name__ == '__main__':
    main()