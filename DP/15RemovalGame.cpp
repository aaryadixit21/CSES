#include <bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Start writing your code here
    int n;
    cin>>n;
    vector<int>score(n);
    for(int i{0}; i<n; ++i) cin>>score[i];
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i>j) {
                dp[i][j] = 0;
                continue;
            }
            if (i==j) {
                dp[i][j] = score[i];
                continue;
            }
            if (j-i==1) {
                dp[i][j] = max(score[i], score[j]);
                continue;
            }

            long long left=score[i] + min((i+2 <= j ? dp[i+2][j] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));
            long long right=score[j] + min((i <= j-2 ? dp[i][j-2] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));

            dp[i][j] = max(left, right);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}