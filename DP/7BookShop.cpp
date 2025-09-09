#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n,x; cin>>n>>x;
    vector<int>prices(n); vector<int>pages(n);
    for(int i{0}; i<n; ++i) cin>>prices[i];
    for(int i{0}; i<n; ++i) cin>>pages[i];
    vector<vector<int>>dp(n+1, vector<int>(x+1, 0));
    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=x; ++j){
            int notpick=dp[i-1][j];
            int pick=0;
            if(j-prices[i-1]>=0){
                pick=dp[i-1][j-prices[i-1]]+pages[i-1];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}