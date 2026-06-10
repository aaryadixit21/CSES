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

void bfs(int &farthestNode, int &farthestDist, vector<int> &dist, queue<int> &q, vvi &v) {
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto child : v[node]) {
            if (dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
                if (dist[child] > farthestDist) {
                    farthestDist = dist[child];
                    farthestNode = child;
                }
            }
        }
    }
    return;
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
    
    queue<int> q;

    //bfs from 1
    vector<int> dist1(n+1, -1);
    q.push(1);
    dist1[1] = 0;
    int farthestNode = 1;
    int farthestDist = 0;
    bfs(farthestNode, farthestDist, dist1, q, v);
    while(!q.empty()) q.pop();


    //bfs from A
    vector<int> dist2(n+1, -1);
    q.push(farthestNode);
    dist2[farthestNode] = 0;
    farthestDist = 0;
    bfs(farthestNode, farthestDist, dist2, q, v);
    while(!q.empty()) q.pop();
    

    //bfs from B
    vector<int> dist3(n+1, -1);
    q.push(farthestNode);
    dist3[farthestNode] = 0;
    farthestDist = 0;
    bfs(farthestNode, farthestDist, dist3, q, v);

    //ans
    for(int i{1}; i <= n; i++){
        cout << max(dist2[i], dist3[i]) << " ";
    }
     cout << endl;
}