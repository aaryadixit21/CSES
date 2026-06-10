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
/*---------------------------------*/


vector<string> grayCode(int n) {
    if (n == 1) return {"0", "1"};

    vector<string> prev = grayCode(n - 1);
    vector<string> ans;

    // Prefix 0 
    for (int i = 0; i < prev.size(); i++) {
        ans.push_back("0" + prev[i]);
    }

    // Prefix 1 
    for (int i = prev.size() - 1; i >= 0; i--) {
        ans.push_back("1" + prev[i]);
    }

    return ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin >> n;
    vector<string> ans = grayCode(n);
    for (auto &x : ans) {
        cout << x << '\n';
    }
}