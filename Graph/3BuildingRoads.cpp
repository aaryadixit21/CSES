#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvi vector<vector<int>>
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
void bfs(int i, vi& vis, vector<vector<int>>& adj){
    vis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto it:adj[curr]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    le(n); le(m);
    vector<vector<int>> adj(n+1);
    for(int i{0}; i<m; ++i){
        le(a); le(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vi s;
    vi vis(n+1,0);
    for(int i{1}; i<=n; ++i){
        if(vis[i]==0){
            s.push_back(i);
            bfs(i,vis,adj);
        }
    }
    int com=s.size();
    cout<<com-1<<endl;
    
    if(com!=1){
        for(int i{0}; i<com-1; ++i){
            cout<<s[i]<<" "<<s[i+1]<<endl;
        }
    }
    
    return 0;
}