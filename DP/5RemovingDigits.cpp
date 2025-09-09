#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>& dp){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    int curr=n;
    int ans=INT_MAX;
    while(curr){
        int d=curr%10;
        curr /= 10;
        if(d>0){
            ans=min(ans, 1+solve(n-d, dp));
        }
    }
    return dp[n]=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    cout<<solve(n, dp)<<endl;
    return 0;
}