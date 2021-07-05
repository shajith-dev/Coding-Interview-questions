#include<iostream>
// #include <math.h>
#include <algorithm>
#include <vector>
// #include <map>

using namespace std;
typedef long long ll;
#define endl "\n"

ll exp(int a,int b){
    ll res=1;
    while(b){
        if(b%2)res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

int n;

int wine(int a[],int s,int e,vector<vector<int>>&dp){
    if(s>e)return 0;
    if(dp[s][e]!=0)return dp[s][e];
    int y=n-(e-s+1)+1;
    return dp[s][e] = max(wine(a,s+1,e,dp)+y*a[s],wine(a,s,e-1,dp)+y*a[e]);
}

void solve(){
    cin>>n;
    int p[n];
    vector<vector<int>>dp(n,vector<int>(n,0));
    int s=0,e=n-1;
    for(int i=0;i<n;i++)cin>>p[i];
    cout<<wine(p,s,e,dp);
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