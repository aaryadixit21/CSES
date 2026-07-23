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

/* int recursion(int sum, vector<int>& coins, vector<int>& dp){
    if(sum == 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    int ans=INT_MAX;
    for(int coin : coins){
        int pick=INT_MAX;
        if(sum-coin>=0) pick=recursion(sum-coin, coins, dp);
        if(pick != INT_MAX) ans = min(ans, pick+1);
    }
    return dp[sum] = ans;
} */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(int i{0}; i<n; ++i){
        cin >> coins[i];
    }
    vector<int> dp(sum+1, -1);
    
    /* int ans=recursion(sum, coins, dp);
    cout<< (ans == INT_MAX ? -1 : ans) << endl; */

    dp[0] = 0;
    for(int i{1}; i<=sum; ++i){
        int ans=INT_MAX;
        for(int coin : coins){
            int pick=INT_MAX;
            if(i-coin>=0) pick=dp[i-coin];
            if(pick != INT_MAX) ans = min(ans, pick+1);
        }
        dp[i] = ans;
    }
    cout << (dp[sum] == INT_MAX ? -1 : dp[sum]) << endl;
}