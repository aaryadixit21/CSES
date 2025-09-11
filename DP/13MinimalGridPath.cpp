#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    cin>>n;
    vector<vector<char>>grid (n, vector<char>(n));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<n; ++j) cin>>grid[i][j];
    }
    vector<vector<string>> dp(n+1, vector<string>(n+1, "~"));
    dp[1][1]=string(1, grid[0][0]);
    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=n; ++j){
            if(i==1 && j==1) continue;
            string right="~", down="~";
            if(j>1) right=dp[i][j-1]+string(1,grid[i-1][j-1]);
            if(i>1) down=dp[i-1][j]+string(1,grid[i-1][j-1]);
            dp[i][j]=min(right, down);
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}