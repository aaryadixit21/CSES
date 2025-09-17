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
    vi vis(n+1, 0);
    vi parent(n+1, -1);
    queue<int>q;
    q.push(1); vis[1]=1;
    bool possible=false;
    while(!q.empty()){
        int size=q.size();
        for(int i{0}; i<size; ++i){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(vis[it]==0){
                    vis[it]=1;
                    parent[it]=curr;
                    if(it==n){
                        possible=true;
                        break;
                    }
                    q.push(it);
                }
            }
            if(possible) break;
        }
        if(possible) break;
    }
    if(!possible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>path;
    int ma=n;
    while(ma!=-1){
        path.push_back(ma);
        ma=parent[ma];
    }
    cout<<path.size()<<endl;
    reverse(all(path));
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}