#!/usr/bin/env python3
import sys
sys.setrecursionlimit(200000) 
# o Python possui um limite de 1000 chamadas recursivas
# é possível fazer a DFS iterativa nesse caso, para escapar disso

MAXN = int(1e5 + 10)

adj = [[] for _ in range(MAXN)]
vis = [False for _ in range(MAXN)]
dp0 = [-1 for _ in range(MAXN)]
dp1 = [-1 for _ in range(MAXN)]

def main():
    n = int(input())
    eco = list(map(int, input().split()))
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    def dfs(v):
        vis[v] = True
        dp1[v] = eco[v]     # se escolher v
        dp0[v] = 0          # se não escolher v
        for u in adj[v]:
            if (vis[u] != True):
                dfs(u)
                dp1[v] += dp0[u]
                dp0[v] += max(dp0[u], dp1[u])
    
    dfs(0)
    
    print(max(dp0[0], dp1[0]))      
    
if __name__ == '__main__':
    main()