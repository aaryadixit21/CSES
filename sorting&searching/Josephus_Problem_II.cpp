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

    
    // Finds smallest index idx such that query(idx) >= k
    // returns kth alive child
    long long kth(int k) {
        int idx = 0;

        //nearest 2 power less than n
        int pow2 = 1;
        while (pow2 * 2 <= n) {
            pow2 *= 2;
        }

        //binary search on fenwick tree
        int mask = pow2;
        while (mask > 0) {
            int next = idx + mask;

            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }

            mask /= 2;
        }

        return idx + 1;
    }


    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
/*---------------------------------*/

void func(){
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    FenwickTree fw(n);
    for(int i = 1; i <= n; i++) {
        fw.update(i, 1);
    }
    int pos = 1;
    for(int i = 1; i <= n; i++) {
        //rem child
        int rem=n-i+1;

        //pos of next child to be removed
        pos=(pos+k)%rem;
        if(pos==0) pos=rem;

        //find the pos of the child to be removed
        int idx=fw.kth(pos);
        cout << idx << " ";


        fw.update(idx, -1);
    }
}