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
struct Customer {
    int start, end, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Customer> cust(n);

    for (int i = 0; i < n; i++) {
        cin >> cust[i].start >> cust[i].end;
        cust[i].idx = i;
    }

    sort(cust.begin(), cust.end(),
         [](const Customer &a, const Customer &b) {
             return a.start < b.start;
         });

    // dp,room
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(n);
    int rooms = 0;

    for (auto &c : cust) {
        if (!pq.empty() && pq.top().first < c.start) {
            auto [dep, room] = pq.top();
            pq.pop();
            ans[c.idx] = room;
            pq.push({c.end, room});
        }
        else {
            rooms++;
            ans[c.idx] = rooms;
            pq.push({c.end, rooms});
        }
    }

    cout << rooms << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}