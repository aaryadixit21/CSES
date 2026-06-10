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

void func(){
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int,int>> a(2*n);
    for(int i{0};i<2*n;i+=2){
        int x,y;
        cin >> x >> y;
        a[i]={x,1};
        a[i+1]={y,2};
    }
    sort(a.begin(), a.end());
    int cnt=0;
    int ans=0;
    for(int i{0}; i<2*n; ++i){
        if(a[i].second==1){
            cnt++;
            ans = max(ans, cnt);
        }
        else{
            cnt--;
        }
    }    
    cout << ans << endl;
}