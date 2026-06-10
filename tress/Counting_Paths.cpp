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

int func(int x, int k, vvi &dp){
    while(k>0 && x!=-1){
        int j=log2(k);
        x=dp[x][j];
        k-=(1<<j);
    }
    return x;
}



int lca(int a, int b, vvi &dp, vector<int> &l){
    if(l[a]>l[b])swap(a, b);
    b=func(b, l[b]-l[a], dp);

    if(a==b){
        return a;
    }
    for(int j=19;j>=0;j--){
        if(dp[a][j]!=dp[b][j]){
            a=dp[a][j];
            b=dp[b][j];
        }
    }
    return dp[a][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vvi dp(n+1, vector<int>(20, -1));
    vector<int> l(n+1, 0), order;
    vvi adj(n+1);
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //bfs
    queue<int> q1;
    q1.push(1);
    vector<bool> vis(n+1, false);
    vis[1]=true;

    while(!q1.empty()){
        int x=q1.front();
        order.push_back(x);
        q1.pop();
        for(auto y: adj[x]){
            if(!vis[y]){
                vis[y]=true;
                dp[y][0]=x;
                l[y]=l[x]+1;
                q1.push(y);
            }
        }
    }

    //filling dp
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]==-1)continue;
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    vector<int> ans(n+1, 0);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        int lca_node = lca(a, b, dp, l);
        ans[a]++;
        ans[b]++;
        ans[lca_node]--;
        if(dp[lca_node][0]!=-1) ans[dp[lca_node][0]]--;
    }
    for(int i=n-1;i>=0;i--){
        int x=order[i];
        if(dp[x][0]!=-1) ans[dp[x][0]]+=ans[x];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}    

