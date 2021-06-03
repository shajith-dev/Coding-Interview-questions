def coin(amt,c,memo=dict()):
    m=1e9
    if amt in memo.keys():
        return memo[amt]
    if amt==0:
        return 0
    for i in range(len(c)):
        if amt-c[i] in memo.keys():
            return memo[amt-c[i]]
        if c[i]<=amt:
            m = min(m,coin(amt-c[i],c,memo))  
        else:
            break
    for i in c:
        memo[amt-i] = 1+m
        return memo[amt-i]

amt = int(input())
c = list(map(int,input().split()))
x = coin(amt,c)
ans = x if x<(1e9+1) else -1
print(ans)
