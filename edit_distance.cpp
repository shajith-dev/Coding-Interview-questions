#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"

int ed(string s1,string s2,int n,int m,vector<vector<int>>&dp){
    if(n==0)return m;
    if(m==0)return n;
    if(dp[n][m])return dp[n][m];
    if(s1[n-1]==s2[m-1]){
        if(dp[n-1][m-1]==0){
            dp[n][m]=ed(s1,s2,n-1,m-1,dp);
        }
        else{
            dp[n][m]=dp[n-1][m-1];
        }
        return dp[n][m];
    }
    else{
        int x,y,z;
        if(dp[n-1][m])x=dp[n-1][m];
        else x=ed(s1,s2,n-1,m,dp);

        if(dp[n-1][m-1])y=dp[n-1][m-1];
        else y=ed(s1,s2,n-1,m-1,dp);

        if(dp[n][m-1])z=dp[n][m-1];
        else z=ed(s1,s2,n,m-1,dp);
        
        dp[n][m] = 1+min(x,min(y,z));
    }
    return dp[n][m];
}

void solve(){
    string s1,s2;
    int n,m;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    cout<<ed(s1,s2,n,m,dp);
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