#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n; cin>>n;
    vector<int>money(n);
    for(int i{0}; i<n; ++i) cin>>money[i];
    vector<int>ans;

    int sum = accumulate(money.begin(), money.end(), 0);
    vector<bool> dp(sum+1, false);
    dp[0] = true;


    for(int i{0}; i<n; ++i){
        for(int j{sum}; j>=0; --j){
            if(dp[j]==true) dp[j+money[i]]=true;
        }
    }

    for(int i{1}; i<=sum; ++i){
        if(dp[i]) ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}