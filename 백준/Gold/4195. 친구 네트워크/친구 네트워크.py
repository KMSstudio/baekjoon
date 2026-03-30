from collections import defaultdict

def solve():
    F = int(input())

    P = defaultdict(lambda: 0)
    S = defaultdict(lambda: 1)

    def FIND(x):
        if P[x] == 0 or P[x] == x: return x
        else: P[x] = FIND(P[x]); return P[x]
    def UNION(x, y):
        x = FIND(x); y = FIND(y)
        if x == y: return
        if(S[y] > S[x]): x, y = y, x
        P[y] = x; S[x] += S[y]

    for i in range(F):
        a, b = input().split()
        UNION(a, b)
        print(S[FIND(a)])

T = int(input())
for t in range(T):
    solve()

