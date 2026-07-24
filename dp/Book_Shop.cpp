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

/* int recursion(int i, int x, int n, vector<pair<int,int>>& arr, vector<vector<int>>& dp){
    if(i==n || x==0) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int pick=0;
    if(arr[i].first<=x){
        pick=arr[i].second+recursion(i+1,x-arr[i].first,n,arr,dp);
    }
    int not_pick = recursion(i+1,x,n,arr,dp);
    return dp[i][x] = max(pick,not_pick);
} */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    //prices,pages
    vector<pair<int,int>> arr(n);
    for(int i{0}; i<n; ++i){
        cin >> arr[i].first;
    }
    for(int i{0}; i<n; ++i){
        cin >> arr[i].second;
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    // cout<<recursion(0,x,n,arr,dp)<<endl;
    for(int i{0}; i<=n; ++i) dp[i][0] = 0;
    for(int i{0}; i<=x; ++i) dp[0][i] = 0;
    
    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=x; ++j){
            int pick=0;
            if(arr[i-1].first<=j){
                pick=arr[i-1].second+dp[i-1][j-arr[i-1].first];
            }
            int not_pick = dp[i-1][j];
            dp[i][j] = max(pick,not_pick);
        }
    }
    cout << dp[n][x] << endl;   
}