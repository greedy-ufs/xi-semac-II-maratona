import sys


def compute_pi(P):
    m = len(P)
    pi = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and P[k] != P[q]:
            k = pi[k-1]
        if P[k] == P[q]:
            k += 1
        pi[q] = k
    return pi

def get_prefix_matches(T, P, pi):
    n = len(T)
    m = len(P)
    matches = [0] * n
    q = 0
    for i in range(n):
        while q > 0 and P[q] != T[i]:
            q = pi[q-1]
        if P[q] == T[i]:
            q += 1
        matches[i] = q
        if q == m:
            q = pi[q-1]
    return matches

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    if len(input_data) < 2:
        return

    M = input_data[0]
    S = input_data[1]

    n = len(S)
    m = len(M)

    if n < m:
        print("NAO MUITO FACIL")
        return

    pi_M = compute_pi(M)
    pref_len = get_prefix_matches(S, M, pi_M)

    M_rev = M[::-1]
    S_rev = S[::-1]
    pi_M_rev = compute_pi(M_rev)
    suff_len_rev = get_prefix_matches(S_rev, M_rev, pi_M_rev)

    suff_len = [0] * n
    for k in range(n):
        suff_len[n - 1 - k] = suff_len_rev[k]

    aprovado = False
    for j in range(1, n):
        i_gap0 = j - 1
        if i_gap0 >= 0:
            if pref_len[i_gap0] > 0 and suff_len[j] > 0 and (pref_len[i_gap0] + suff_len[j] == m):
                aprovado = True
                break
        
        i_gap1 = j - 2
        if i_gap1 >= 0:
            if pref_len[i_gap1] > 0 and suff_len[j] > 0 and (pref_len[i_gap1] + suff_len[j] == m):
                aprovado = True
                break

    if aprovado:
        print("MUITO FACIL")
    else:
        print("NAO MUITO FACIL")

if __name__ == '__main__':
    solve()