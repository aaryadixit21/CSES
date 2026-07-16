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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, pair<int,int>> mp;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            ll need = x - a[i] - a[j];

            if (mp.count(need)) {

                auto [p, q] = mp[need];

                if (p != i && p != j &&
                    q != i && q != j) {

                    cout << p + 1 << " "
                         << q + 1 << " "
                         << i + 1 << " "
                         << j + 1 << '\n';

                    return 0;
                }
            }
        }

        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";
}