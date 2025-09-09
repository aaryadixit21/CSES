#include <bits/stdc++.h>
using namespace std;
int MOD=1e9 + 7;
int solve(int n, vector<int>& dp){
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];
    int temp=0;
    for(int i{1}; i<=6; ++i){
        if(n-i>=0){
            temp=(temp+solve(n-i, dp))%MOD;
        }
    }
    return dp[n]=temp % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n;
    cin>>n;
    vector<int>dp (n+1, -1);
    int ans=solve(n, dp) % MOD;
    cout<<ans<<endl;
    return 0;
}