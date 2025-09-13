#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long solve(int i, int j, vector<vector<int>>& dp){
    if(i==0) return 1;
    if(i==1 && j==1) return 1;
    if(i==1 && j==2) return 2;

    if(dp[i][j]!=-1) return dp[i][j];
    //vertical
    long long ans=0;
    if(j==2) ans=(ans+solve(i,1,dp))%mod;

    //horizontal
    for(int k=1; k<i; ++k){
        long long temp=(solve(k,j,dp) * solve(i-k,j,dp))%mod;
        ans=(ans+temp)%mod;
    }

    return dp[i][j]=ans;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        vector<vector<int>>dp(n+1, vector<int>(3,-1));
        cout<<solve(n,2,dp)<<endl;
    }
    return 0;
}