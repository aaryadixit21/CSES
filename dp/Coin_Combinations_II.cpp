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

/* int recursion(int sum, int i,vector<int>& coins, vector<vector<int>>& dp){
    if(sum==0) return 1;
    if(sum<0) return 0;
    if(i>=coins.size()) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int pick=recursion(sum-coins[i],i,coins,dp)%M;
    int notPick=recursion(sum,i+1,coins,dp)%M;
    return dp[i][sum]=(pick+notPick)%M;
} */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(int i{0}; i<n; ++i) cin >> coins[i];
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    // cout<<recursion(sum, 0, coins,dp)%M<<endl;
    for(int i{0}; i<=n; ++i) dp[i][0] = 1;
    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=sum; ++j){
            int pick = (j - coins[i - 1] >= 0) ? dp[i][j - coins[i - 1]] % M : 0;
            int notPick = dp[i - 1][j] % M;
            dp[i][j] = (pick + notPick) % M;
        }
    }
    prnt(dp[n][sum]);
}