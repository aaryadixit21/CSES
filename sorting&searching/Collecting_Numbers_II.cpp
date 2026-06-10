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
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n+1), pos(n+1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
        arr[i] = x;
    }

    int rounds = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] > pos[i+1]) rounds++;
    }

    for(int k = 0; k < m; k++) {
        int x, y;
        cin >> x >> y;
        
        int a= arr[x], b = arr[y];

        set<int> s;
        s.insert(a);
        s.insert(b);
        if(a > 1) s.insert(a-1);
        if(b > 1) s.insert(b-1);

        for(auto it:s){
            if(pos[it] > pos[it+1]) rounds--;
        }

        swap(arr[x], arr[y]);
        swap(pos[a], pos[b]);

        for(auto it:s){
            if(pos[it] > pos[it+1]) rounds++;
        }
        cout << rounds<< endl;
    }
    
    
}