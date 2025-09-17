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
bool possible=false;
int s;
int e;
void bfs(int i, vvi& adj, vi& parent){
    parent[i]=0;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto it:adj[curr]){
            if(parent[it]==-1){
                parent[it]=curr;
                q.push(it);
            }
            else if(parent[curr]==it) continue;
            else{
                possible=true;
                s=curr; e=it;
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

    vi parent(n+1, -1);
    for(int i{1}; i<=n; ++i){
        if(parent[i]==-1){
            bfs(i, adj, parent);
            if(possible) break;
        }
    }
    
    if(possible){
        vector<int> path1, path2;

        int x = s;
        while (x != 0) {
            path1.push_back(x);
            x = parent[x];
        }

        int y = e;
        while (y != 0) {
            path2.push_back(y);
            y = parent[y];
        }

        int lca = -1;
        unordered_set<int> seen(path1.begin(), path1.end());
        for (int node : path2) {
            if (seen.count(node)) {
                lca = node;
                break;
            }
        }
        vector<int> cycle;
        int u = s;
        while (u != lca) {
            cycle.push_back(u);
            u = parent[u];
        }
        cycle.push_back(lca);
        reverse(all(cycle));
        vector<int> tmp;
        int v = e;
        while (v != lca) {
            tmp.push_back(v);
            v = parent[v];
        }
        
        for (auto node : tmp) cycle.push_back(node);

        cycle.push_back(lca);

        cout<<cycle.size()<<endl;
        for(auto it:cycle){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}