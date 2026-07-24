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

void func(){
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, 0));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<n; ++j){
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n,0));
    if(grid[0][0]=='.') dp[0][0]=1;
    else {
        cout << 0 << endl;
        return 0;
    }
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<n; ++j){
            if(grid[i][j]=='*') dp[i][j]=0;
            else{
                if(i-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
                if(j-1>=0) dp[i][j] = (dp[i][j] + dp[i][j-1])%M;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}