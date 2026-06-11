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
    
    int x,n;
    cin >> x >> n;
    set<int>s;
    multiset<int>possible;
    s.insert(0);
    s.insert(x);
    possible.insert(x);
    for(int i{0}; i<n; ++i){
        int p;
        cin >> p;
        auto it=s.upper_bound(p);
        int b=*it;
        int a=*(--it);
        s.insert(p);
        possible.erase(possible.find(b-a));
        possible.insert(p-a);
        possible.insert(b-p);
        cout << *possible.rbegin() << " ";
    }
}