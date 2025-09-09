#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= x; sum++) {
        int ways = 0;
        for (int i = 0; i < n; i++) {
            int c = coins[i];
            if (c > sum) continue;
            ways += dp[sum - c];
            if (ways >= MOD) ways -= MOD;
        }
        dp[sum] = ways;
    }

    cout << dp[x] << "\n";
    return 0;
}
