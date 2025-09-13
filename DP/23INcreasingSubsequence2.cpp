#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    cin>>n;
    vector<int>a(n);
    for(int i{0}; i<n; ++i) cin>>a[i];
    vector<long long>dp(n,1);   
    long long ans=0;
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<i; ++j){
            if(a[i]>a[j]){
                dp[i]=(dp[i]+dp[j])%mod;
            }
        }
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<< endl;
    return 0;
}