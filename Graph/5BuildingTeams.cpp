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
bool possible=true;
void bfs(int i, vi& vis, vvi& adj){
    vis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        int x=vis[curr];
        q.pop();
        for(auto it:adj[curr]){
            if(vis[it]==0){
                if(x==1){
                    vis[it]=2;
                }
                else vis[it]=1;

                q.push(it);
            }
            else if(vis[it]==x){
                possible=false;
                return;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    le(n); le(m);
    vvi adj(n+1);
    for(int i{0}; i<m; ++i){
        le(a); le(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi vis(n+1, 0);
    for(int i{1}; i<=n; ++i){
        if(vis[i]==0){
            bfs(i,vis,adj);
            if(!possible){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i{1}; i<=n; ++i){
        cout<<vis[i]<<" ";
    }
    cout<<endl;
    return 0;
}