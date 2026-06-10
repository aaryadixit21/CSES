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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,q;
    cin>>n>>q;
    vvi dp(n+1, vector<int>(20, -1));
    for(int i=2;i<=n;i++){
        cin>>dp[i][0];
    }

    //filling dp
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]==-1)continue;
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }    

    for(int i{0}; i<q; ++i){
        int x,k;
        cin>>x>>k;
        cout<<func(x, k, dp)<<endl;
    }
}