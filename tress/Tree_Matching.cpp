#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvi vector<vector<int>>
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
int ans = 0;

void dfs(int node, vvi &v, vector<int> &vis, vector<int> &match){
    vis[node] = 1;
    for(auto child : v[node]){
        if(!vis[child]){
            dfs(child, v, vis, match);
            if(match[node] == -1 && match[child] == -1){
                match[node] = child;
                match[child] = node;
                ans++;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vvi v(n+1);
    vector<int>vis(n+1, 0);
    vector<int>match(n+1, -1);
    for(int i{1}; i < n; i++){
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, v, vis, match);
    prnt(ans);
}