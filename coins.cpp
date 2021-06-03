#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"
 
int coin(int amt,int n,vector<int>dp,vector<int>c){
    dp[0]=0;
    for(int i=0;i<=amt;i++){
        for(int j=0;j<n;j++){
            if(i>=c[j]){
                dp[i] = min(dp[i],1+dp[i-c[j]]);
            }
            else{
                break;
            }
        }
    }
    return dp[amt]>amt?-1:dp[amt];
}

void solve(){
    int amt,n;
    cin>>n>>amt;
    vector<int>dp(amt+1,amt+1),c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    sort(c.begin(),c.end());
    cout<<coin(amt,n,dp,c);
}
 
int main()
{   std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    while(t--)solve();
    return 0;
}