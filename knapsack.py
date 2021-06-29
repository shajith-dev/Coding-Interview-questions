n = int(input())
wt = list(map(int,input().split()))
val = list(map(int,input().split()))
w = int(input())
dp = [[0 for i in range(w+1)] for j in range(n+1)]
def ks(w,wt,val,n):
    if n==0 or w==0:
        return 0
    if dp[n][w]:
        return dp[n][w]
    if wt[n-1]<=w:
        dp[n][w] = max(val[n-1]+ks(w-wt[n-1],wt,val,n-1),ks(w,wt,val,n-1))
    else:
        dp[n][w] = ks(w,wt,val,n-1)
    return dp[n][w]
print(ks(w,wt,val,n))