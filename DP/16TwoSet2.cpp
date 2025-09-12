#include <bits/stdc++.h>
using namespace std;
int mod=7+1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n; cin>>n;
    int target=(n*(n+1))/2;
    if(target%2){
        cout<<0<<endl;
        return 0;
    }
    int sum=target/2;
    vector<vector<long long>>dp(n+1, vector<long long>(sum+1, 0));
    dp[0][0]=1;
    //1 to n-1 elements, vo wale subset kr rhe hain jab last element sirf first subset me ho
    for(int i{1}; i<n; ++i){
        for(int j{0}; j<=sum; ++j){
            long long notake=dp[i-1][j];
            long long take=0;
            if(j-i>=0){
                take=dp[i-1][j-i];
            }
            dp[i][j]=(take+notake)%mod;
        }
    }
    //n-1 elements se sum-n banana hai bcoz n to already hai
    //to sirf unique subset count ho rhe hain
    cout<<dp[n-1][sum-n]%mod<<endl;
    return 0;
}