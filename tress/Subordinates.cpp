#include<bits/stdc++.h>
using namespace std;
#define int long long
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



int func(int node, vector<int>& child, const vvi& v){
    if(child[node] != -1) return child[node];
    else if(v[node].size() == 0){
        return child[node]=1;
    }
    int ans = 0;
    for(auto it : v[node]){
        ans += func(it, child, v);
    }
    return child[node] = ans+1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vvi v(n+1);
    for(int i = 2; i <= n; i++){
        int x; cin>>x;
        v[x].push_back(i);
    }
    vector<int> child(n+1, -1);
    for(int i{1}; i <= n; i++){
        child[i]=func(i, child, v);
    }
    for(int i = 1; i <= n; i++){
        prnt(child[i]-1);
    }
}