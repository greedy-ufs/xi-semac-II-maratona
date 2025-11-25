#!/usr/bin/env python3

HORIZONTAL_INICIO = 0
VERTICAL = 1
HORIZONTAL_FIM = 2

MAX_Y = int(2 * 1e6 + 1)

class Fenwick:
    def __init__(self, size):
        self.n = size
        self.bit = [0] * (size + 1)
    
    def qry(self, r):
        ans = 0
        i = r + 1
        while i > 0:
            ans += self.bit[i]
            i -= i & -i
        return ans
    
    def upd(self, r, x):
        i = r + 1
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

def main():
    n = int(input())

    ev = []
    y_horizontal = [0] * n
    y_vertical = [(0, 0)] * n

    for i in range(n):
        x1, y1, x2, y2 = map(int, input().split())
        if x1 == x2:
            # Vertical line
            ev.append((x1, VERTICAL, i))
            y_vertical[i] = (y1, y2)
        else:
            # Horizontal line
            ev.append((x1, HORIZONTAL_INICIO, i))
            ev.append((x2, HORIZONTAL_FIM, i))
            y_horizontal[i] = y1

    ev.sort()

    tree = Fenwick(MAX_Y)

    ans = 0
    for x, tipo, id_linha in ev:
        if tipo == HORIZONTAL_INICIO:
            yh = y_horizontal[id_linha]
            tree.upd(yh + int(1e6), 1)
        elif tipo == HORIZONTAL_FIM:
            yh = y_horizontal[id_linha]
            tree.upd(yh + int(1e6), -1)
        else:  # VERTICAL
            y1, y2 = y_vertical[id_linha]
            ans += tree.qry(y2 + int(1e6)) - tree.qry(y1 + int(1e6))

    print(ans)

if __name__ == '__main__':
    main()