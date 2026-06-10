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

string s;
bool vis[9][9];

int dfs(int idx, int r, int c) {
    if (r == 7 && c == 1) return idx == 48;
    if (idx == 48) return 0;

    // up down or left right, blocked 
    if (vis[r][c - 1] && vis[r][c + 1] && !vis[r - 1][c] && !vis[r + 1][c]) return 0;
    if (vis[r - 1][c] && vis[r + 1][c] && !vis[r][c - 1] && !vis[r][c + 1]) return 0;

    vis[r][c] = true;
    int ans = 0;

    char ch = s[idx];

    if ((ch == 'U' || ch == '?') && !vis[r - 1][c]) ans += dfs(idx + 1, r - 1, c);
    if ((ch == 'D' || ch == '?') && !vis[r + 1][c]) ans += dfs(idx + 1, r + 1, c);
    if ((ch == 'L' || ch == '?') && !vis[r][c - 1]) ans += dfs(idx + 1, r, c - 1);
    if ((ch == 'R' || ch == '?') && !vis[r][c + 1]) ans += dfs(idx + 1, r, c + 1);

    vis[r][c] = false;
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    //boundary
    for (int i = 0; i < 9; i++) {
        vis[0][i] = vis[8][i] = true;
        vis[i][0] = vis[i][8] = true;
    }

    cout << dfs(0, 1, 1) << '\n';
}
