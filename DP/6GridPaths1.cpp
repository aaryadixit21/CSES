#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<n; ++j){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i{0}; i<n; ++i){
        if(grid[i][0]=='*') break;
        dp[i][0]=1;
    }
    for(int i{0}; i<n; ++i){
        if(grid[0][i]=='*') break;
        dp[0][i]=1;
    }
    int mod=7+1e9;
    for(int i{1}; i<n; ++i){
        for(int j{1}; j<n; ++j){
            if(grid[i][j]=='*') continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}