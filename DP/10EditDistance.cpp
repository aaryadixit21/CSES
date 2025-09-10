#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    string a;
    string b;
    cin>>a>>b;
    n=a.length();
    m=b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    for(int i{0}; i<=n; ++i) dp[i][0]=i;
    for(int j{0}; j<=m; ++j) dp[0][j]=j;

    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=m; ++j){
            int replace=dp[i-1][j-1];
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int remove=dp[i-1][j];
                int add=dp[i][j-1];
                dp[i][j]=1+min(replace, min(remove, add));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}