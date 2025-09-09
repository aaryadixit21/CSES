#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i{0}; i<n; ++i){
        cin>>coins[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1, 1e9));
    for(int i{0}; i<=n; ++i) dp[i][0]=0;

    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=x; ++j){
            int notpick= dp[i-1][j];
            int pick=1e9;
            if(j-coins[i-1]>=0){
                pick=dp[i][j-coins[i-1]]+ 1;
            }
            dp[i][j]=min(pick, notpick);
        }
    }
    int ans=dp[n][x];
    if(ans>=1e9) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}