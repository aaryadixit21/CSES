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

class FenwickTree {
private:
    vector<long long> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long delta) {
        while(i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
/*---------------------------------*/

bool possible(ll time, vector<int>& v, int t){
    ll z=0;
    for(auto it:v){
        z+=time/it;
        if(z>=t) return true;
    }    
    return z>=t;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,t;
    cin >> n >> t;

    vector<int>v(n);
    int x=0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        x=max(x,v[i]);
    }
    ll s=0;
    ll e=(ll)x*t;
    while(s<=e){
        long long mid=s+(e-s)/2;
        if(possible(mid,v,t)){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    prnt(s);
}