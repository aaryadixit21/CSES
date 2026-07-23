#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vvi vector<vector<int>>
#define vll vector<ll>
#define pll pair<long,long>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define take(arr, n) \
    vector<ll> arr(n); \
    for(auto &it : arr) cin >> it
const ll M = 1000000007;
#define le(x) \
    ll x; \
    cin >> x
#define prnt(a) cout << a << endl

/*---------------------------------*/
string abc = "abcdefghijklmnopqrstuvwxyz";
const ll N = 100005;
int dp[1000005];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

class FenwickTree {
private:
    vector<long long> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int index, long long delta) {
        while(index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while(index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
/*---------------------------------*/

/* int recursion(int sum, vector<int> &dp){
    if(dp[sum] != -1){
        return dp[sum];
    }
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    int ans = 0;
    for(int i{1}; i<=6; ++i){
        int pick=0;
        if(sum-i >= 0) pick = recursion(sum-i, dp) % M;
        ans = (ans + pick) % M;
    }

    return dp[sum] = ans;
} */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sum;
    cin >> sum;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    // cout << recursion(sum, dp) << endl;

    for(int i{1}; i<=sum; ++i){
        for(int j{1}; j<=6; ++j){
            int pick=0;
            if(i-j >= 0) pick = dp[i-j] % M;
            dp[i] = (dp[i] + pick) % M;
        }
    }
    cout << dp[sum] << endl;
}