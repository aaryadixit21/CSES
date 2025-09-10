#include <bits/stdc++.h>
using namespace std;
int mod=7+1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i{0}; i<n; ++i) cin>>a[i];
    vector<vector<int>>dp (n+1, vector<int>(m+1, 1));
    for(int i{1}; i<=n; ++i){
        for(int j{0}; j<=m; ++j){
            int ans=0;
            if(a[i-1]!=0){
                if(j==0 || abs(a[i-1]-j) <= 1){
                    ans=dp[i-1][a[i-1]];
                }
            }  
            else{
                if(j==0){
                    for(int k{1}; k<=m; ++k){
                        ans=(ans+dp[i-1][k])%mod;   
                    }
                }
                else{
                    for(int k=-1; k<=1; ++k){
                        if(k+j<=m && k+j>0){
                            ans=(ans+dp[i-1][k+j])%mod;
                        }
                    }
                }
            }
            dp[i][j]=ans%mod;
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}