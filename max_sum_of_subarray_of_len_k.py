a = list(map(int,input().split()))
k=int(input())
l=0
m=-1000
sum=0
for r in range(len(a)):
    sum+=a[r]
    while(r-l+1>k):
        sum-=a[l]
        l+=1
    if r-l+1==3:
        m = max(m,sum)
print(m)