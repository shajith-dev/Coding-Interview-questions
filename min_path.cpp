#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"

 
int main()
{   std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int r,c;
    cin>>r>>c;
    int dp[r][c],p[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>p[i][j];
            dp[i][j]=0;
        }
    }
    dp[0][0]=p[0][0];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 && j>=1)dp[i][j]=p[i][j]+dp[i][j-1];
            else if(j==0 && i>=1)dp[i][j]+=p[i][j]+dp[i-1][j];
            else if(i!=0 && j!=0){
                dp[i][j]=p[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }   
    cout<<dp[r-1][c-1];
    return 0;
}