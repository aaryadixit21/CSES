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

int ktop(int node, int k, vvi& dp){
    while(k>0 && node!=-1){
        int j=log2(k);
        node=dp[node][j];
        k-=(1<<j);
    }
    return node;
}

int lcanode(int a, int b, vvi& dp, vector<int>& l){
    if(l[a]>l[b])swap(a, b);
    b=ktop(b, l[b]-l[a], dp);

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

void subtreesumcal(int node, vvi& adj, vector<int>& subtreesum, vector<int>& v, vvi& dp, vector<int>& order){
    //subtree sum
    subtreesum[node]+=v[node];
    for(int i=order.size()-1;i>=0;i--){
        int x=order[i];
        for(auto y: adj[x]){
            if(y!=dp[x][0]){
                subtreesum[x]+=subtreesum[y]+v[y];
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1), subtreesum(n+1, 0);

    for(int i{1};i<=n;i++){
        cin>>v[i];
    }

    vvi adj(n+1);
    for(int i{0};i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //bfs
    int log=20;
    vvi dp(n+1, vector<int>(log, -1));
    vector<int> order, vis(n+1, 0);
    vector<int> l(n+1, 0);
    queue<int> q1;
    q1.push(1);
    vis[1] = 1;

    while(!q1.empty()){
        int x=q1.front();
        q1.pop();
        order.push_back(x);
        for(auto y: adj[x]){
            if(!vis[y]){
                vis[y]=true;
                l[y]=l[x]+1;
                q1.push(y);
                dp[y][0]=x;
            }
        }
    }
    


    //binary lifting
    for(int i=1; i<log; i++){
        for(int j{1}; j<=n; j++){
            if(dp[j][i-1]!=-1){
                dp[j][i]=dp[dp[j][i-1]][i-1];
            }
        }
    }

    vector<int> actual(n+1);
    for(int i=1;i<=n;i++){
        actual[i]=i;
    }

    //queries
    bool flag=true;
    while(q--){
        int type;
        cin>>type;
        if(type==2){
            int s;
            cin>>s;
            if(!flag){
                subtreesumcal(actual[s], adj, subtreesum, v, dp, order);
                flag=true;
            }
            cout<<v[actual[s]]+subtreesum[actual[s]]<<endl;
        }
        else{
            flag=false;
            int s,x;
            cin>>s>>x;
            swap(actual[s], actual[x]);
        }
    }

}    