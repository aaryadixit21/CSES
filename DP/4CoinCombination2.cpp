#include <bits/stdc++.h>
using namespace std;

int mod=7+1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i{0}; i<n; ++i) cin>>coins[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i{0}; i<=n; ++i) dp[i][0]=1;

    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=x; ++j){
            int notpick=dp[i-1][j];
            int pick=0;
            if(j-coins[i-1]>=0){
                pick=dp[i][j-coins[i-1]];
            }
            dp[i][j]=(pick+notpick)%mod;
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}