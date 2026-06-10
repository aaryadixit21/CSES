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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n;
    cin >> n;
    vector<ll> v1,v2;
    long long sum= n*(n+1)/2;
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    sum/=2;
    
    for(ll i=n;i>=1;i--){
        if(sum-i>=0){
            v1.push_back(i);
            sum-=i;
        }
        else{
            v2.push_back(i);
        }
    }
    cout<<v1.size()<<endl;
    for(auto it:v1){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<v2.size()<<endl;
    for(auto it:v2){
        cout<<it<<" ";
    }
    cout<<endl;
}    