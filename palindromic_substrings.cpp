#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define endl "\n"
vector<vector<int>> dp, vis;
#define MAX_SIZE 1000005
int go(int i, int j, string &s)
    {
        if (i > j)
            return 1;
        if (i == j)
            return 1;
        if (vis[i][j])
            return dp[i][j];
        vis[i][j] = 1;
        if (s[i] != s[j])
            return dp[i][j] = 0;

        return dp[i][j] = go(i + 1, j - 1, s);
    }

int countSubstrings(string s)
{

    int n = s.size();
    dp.resize(n, vector<int>(n, -1));
    vis.resize(n, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            ans += go(i, j, s);
        }

        return ans;
}
void solve(){
    string s;
    cin>>s;
    int a=countSubstrings(s);
    cout<<a;
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