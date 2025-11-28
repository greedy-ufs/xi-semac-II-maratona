import sys

MAX_COORD = 105
G = [[0] * MAX_COORD for _ in range(MAX_COORD)]

def calculate_mex(l, c):
    reachable = set()
    
    for k in range(l):
        reachable.add(G[k][c])
        
    for k in range(c):
        reachable.add(G[l][k])
        
    u = 1
    while l - u >= 0 and c - u >= 0:
        reachable.add(G[l - u][c - u])
        u += 1
        
    mex = 0
    while mex in reachable:
        mex += 1
    return mex

def precompute_grundy():
    G[0][0] = 0
    for l in range(101):
        for c in range(101):
            if l == 0 and c == 0: continue
            G[l][c] = calculate_mex(l, c)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    try:
        n_str = next(iterator)
        N = int(n_str)
        
        xor_sum = 0
        for _ in range(N):
            l = int(next(iterator))
            c = int(next(iterator))
            xor_sum ^= G[l][c]
            
        if xor_sum > 0:
            print("Breno")
        else:
            print("Adversario")
            
    except StopIteration:
        pass

if __name__ == '__main__':
    precompute_grundy()
    solve()