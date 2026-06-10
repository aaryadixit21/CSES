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
{\
    vector<ll> arr(n); \
    for(auto &it : arr) cin >> it; \
}    
const ll M = 1000000007;
#define le(x) \
{\
    ll x; \
    cin >> x; \
}
#define prnt(a) cout << a << endl

/*---------------------------------*/
string abc = "abcdefghijklmnopqrstuvwxyz";
const ll N = 100005;
int dp[1000005];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
/*---------------------------------*/
int diameter = 0;

int height(int node, int parent, vvi &v, vector<int> &h) {
    if (h[node] != -1) return h[node];

    int max1 = 0, max2 = 0;

    for (auto child : v[node]) {
        if (child == parent) continue; 

        int hc = height(child, node, v, h);

        if (hc > max1) {
            max2 = max1;
            max1 = hc;
        } else if (hc > max2) {
            max2 = hc;
        }
    }

    diameter = max(diameter, max1 + max2);

    return h[node] = max1 + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n; cin >> n;

    vvi v(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);   
    }

    vector<int> h(n + 1, -1); 

    height(1, -1, v, h);      

    cout << diameter << endl;

}