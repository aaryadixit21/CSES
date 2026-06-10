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
    
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for(int i{0};i<n;i++){
        int val;
        cin >> val;
        a[i]={val, i+1};
    }
    sort(a.begin(), a.end());
    int i=0, j=n-1;
    while(i<j){
        int sum=a[i].first+a[j].first;
        if(sum==x){
            cout << a[i].second << " " << a[j].second << endl;
            return 0;
        } else if(sum<x){
            i++;
        } else {
            j--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}