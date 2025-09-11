#include <bits/stdc++.h>
using namespace std;
int a; int b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    cin>>a>>b;
    if(a>b) swap(a,b);
    vector<vector<int>> dp(a+1, vector<int>(b+1 ,0));
    for(int i{1}; i<=a; ++i) dp[i][1]=i-1;  
    for(int i{1}; i<=b; ++i) dp[1][i]=i-1;

    for(int i{2}; i<=a; ++i){
        for(int j{2}; j<=b; ++j){
            int ans=INT_MAX;
            if(i==j){
                ans=0;
            }
            else{
                //vertical
                for(int k{1}; k<j; ++k){
                    ans=min(ans, 1+dp[i][k]+dp[i][j-k]);
                }
                //horizontal
                for(int k{1}; k<i; ++k){
                    ans=min(ans, 1+dp[k][j]+dp[i-k][j]);
                }
            }
            dp[i][j]=ans;
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}