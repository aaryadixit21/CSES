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
long long sum=0;
int n;
long long ans=INT_MAX;
void func(long long half, vector<int>& v, int i, long long curr_sum){
    if(curr_sum>half) return;
    if(i==n){
        ans=min(ans, abs(sum-2*curr_sum));
        return;
    }
    //pick
    curr_sum+=v[i];
    func(half, v, i+1, curr_sum);
    //not pick
    curr_sum-=v[i];
    func(half, v, i+1, curr_sum);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum+= (long long)v[i];
    }
    sort(v.begin(), v.end());
    func(sum/2, v, 0, 0);
    prnt(ans);
}