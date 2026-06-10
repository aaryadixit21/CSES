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

void dfs(int node, int parent, vector<int> &subtreeSize, vector<int> &dp, vvi &v) {
    if(dp[node] != -1) return;
    subtreeSize[node] = 1;
    dp[node] = 0;
    for (auto child : v[node]) {
        if (child != parent) {

            dfs(child, node, subtreeSize, dp, v);

            subtreeSize[node] += subtreeSize[child];
            dp[node] += dp[child] + subtreeSize[child];
        }
    }
   
}

void rerooting(int node, int parent, vector<int> &subtreeSize, vector<int> &ans, vvi &v){
    for(auto child: v[node]){
        if(child!=parent){
            int prev=node;
            int next=child;
            ans[child]= ans[prev] - subtreeSize[next] + (subtreeSize.size()-1 - subtreeSize[next]);
            rerooting(child, node, subtreeSize, ans, v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    vvi v(n+1);
    for(int i{1}; i < n; i++){
        int x, y; cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int>subtreeSize(n+1, 0);
    vector<int>dp(n+1, -1);

    dfs(1, 0, subtreeSize, dp, v);

    vector<int> ans(n+1, 0);
    ans[1] = dp[1];
    rerooting(1, 0, subtreeSize, ans, v);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}    