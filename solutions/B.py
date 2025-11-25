#!/usr/bin/env python3
from collections import deque

MAXN = 100010

def main():
    n, m = map(int, input().split())

    adj = [[] for _ in range(MAXN)]
    dist = [-1] * MAXN
    vis = [False] * MAXN

    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    # BFS from node 0
    q = deque([0])
    vis[0] = True
    dist[0] = 0

    while q:
        v = q.popleft()
        for u in adj[v]:
            if not vis[u]:
                dist[u] = dist[v] + 1
                q.append(u)
                vis[u] = True

    if not vis[n - 1]:
        print("MAUS CAMINHOS!")
    else:
        print(dist[n - 1] + 1)

if __name__ == '__main__':
    main()