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
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
/*---------------------------------*/

void func(){
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vvi grid(n, vector<int>(n,INT_MAX));
    grid[0][0] = 0;
    //bfs
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0; i<8; ++i){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == INT_MAX){
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}    
    