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
int dr[4] = {-1, 0, 0, 0};
int dc[4] = {0, -1, -1, 1};
/*---------------------------------*/

int n,m;
bool func(int i,int j, vector<vector<char>>& grid){
    if(i==n) return true;
    if(j==m) return func(i+1,0,grid);

    unordered_set<char> set;
    char current = grid[i][j];
    set.insert(current);
    for(int k=0; k<2; ++k){
        int ni = i + dr[k];
        int nj = j + dc[k];
        if(ni>=0 && ni<n && nj>=0 && nj<m){
            set.insert(grid[ni][nj]);
        }
    }
    bool flag=false;
    for(char c='A'; c<='D'; ++c){
        if(set.find(c)==set.end()){
            grid[i][j]=c;
            if(func(i,j+1,grid)) {
                flag=true;
                return true;
            }    
        }
        if(flag) break;
    }   
    if(!flag) grid[i][j]=current;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<m; ++j){
            cin>>grid[i][j];
        }
    }
    
    
    if(!func(0,0,grid)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    } 
    for(int i{0}; i<n; ++i){
        for(int j{0}; j<m; ++j){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}    