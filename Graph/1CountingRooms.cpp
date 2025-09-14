#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
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
#define dikha(a) cout << a << endl

//---------------------------------/
string abc = "abcdefghijklmnopqrstuvwxyz";
const ll N = 100005;
int dp[1000005];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<char> mapping = {'U', 'D', 'L', 'R'};
//---------------------------------/

void bfs(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<char>>& grid){
    vis[i][j]=1;
    queue<pair<int,int>>que;
    que.push({i,j});
    while(!que.empty()){
        int x=que.size();
        for(int y=0; y<x; ++y){
            int p=que.front().first;
            int q=que.front().second;
            que.pop();
            for(int k{0}; k<4; ++k){
                int newi=p+dr[k];
                int newj=q+dc[k];
                if(newi<n && newi>=0 && newj<m && newj>=0 && grid[newi][newj]=='.' && vis[newi][newj]==0){
                    vis[newi][newj]=1;
                    que.push({newi, newj});
                }
            }
        }
    }
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    le(n); le(m);
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<m; ++j) cin>>grid[i][j];
    }

    int ans=0;
    vector<vector<bool>>vis(n, vector<bool>(m,0));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<m; ++j){
            if(grid[i][j]=='.' && vis[i][j]==0){
                ans++;
                bfs(i,j,n,m,vis,grid);
            }
        }
    }
    dikha(ans);
    return 0;
}