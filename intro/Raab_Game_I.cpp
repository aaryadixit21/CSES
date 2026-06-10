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
    int n,a,b;
    cin >> n >> a >> b;
    if(a+b>n){
        cout<<"NO"<<endl;
        return;
    }
    if((a==0 && b!=0) || (a!=0 && b==0)){
        cout<<"NO"<<endl;
        return;
    }
    int e=n-(a+b);
    vector<int>aa(n),bb(n);
    for(int i{1}; i<=n; ++i){
        aa[i-1]=i;
    }
    int idx=n-1;
    while(e--){
        bb[idx]=aa[idx];
        idx--;
    }
    for(int i{0}; i<=idx; ++i){
        bb[i]=aa[(i+a)%(idx+1)];
    }
    cout<<"YES"<<endl;
    for(int i{0}; i<n; ++i){
        cout<<aa[i]<<" ";
    }
    cout<<endl;
    for(int i{0}; i<n; ++i){
        cout<<bb[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        func();
    }
}