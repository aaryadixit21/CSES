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

    void update(int index, long long delta) {
        while(index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while(index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
/*---------------------------------*/

void func(){
   
}
class Range {
public:
    int l, r, idx;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin >> n;

    vector<Range> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }

    sort(a.begin(), a.end(), [](const Range &A, const Range &B) {
        if (A.l == B.l)
            return A.r > B.r;   // larger interval first
        return A.l < B.l;
    });

    int minR = INT_MAX;
    vector<int> contains(n, 0);
    for(int i{n-1}; i>=0; --i){
        if(a[i].r >= minR){
            contains[a[i].idx] = 1;
        }
        minR = min(minR, a[i].r);
    }

    for(int i{0}; i<n; ++i){
        cout << contains[i] << " ";
    }
    cout << endl;
    int maxR = 0;
    vector<int> contained(n, 0);
    for(int i{0}; i<n; ++i){
        if(a[i].r <= maxR){
            contained[a[i].idx] = 1;
        }
        maxR = max(maxR, a[i].r);
    }

    for(int i{0}; i<n; ++i){
        cout << contained[i] << " ";
    }
    cout << endl;
}