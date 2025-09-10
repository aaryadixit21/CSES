#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n; int m;
    cin>>n>>m;
    vector<int>a(n); vector<int>b(m);
    for(int i{0}; i<n; ++i) cin>>a[i];
    for(int i{0}; i<m; ++i) cin>>b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=m; ++j){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;   
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    
    int i=n; int j=m;
    vector<int>lcs;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs.push_back(a[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    for(auto it:lcs){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}