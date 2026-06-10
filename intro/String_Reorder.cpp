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

bool possible(vector<int>& freq, int rem, int prev){
    for(int c = 0; c < 26; c++){
        int limit;
        if(c == prev) limit = rem / 2;
        else limit = (rem + 1) / 2;

        if(freq[c] > limit) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'A']++;
        if(freq[c - 'A'] > (n + 1) / 2){
            cout << -1 << endl;
            return 0;
        }
    }

    string ans = "";
    int prev = -1;

    for(int i = 0; i < n; i++){
        bool found = false;

        for(int c = 0; c < 26; c++){
            if(freq[c] == 0) continue;
            if(c == prev) continue;

            freq[c]--;
            int rem = n - i - 1;

            if(possible(freq, rem, c)){
                ans.push_back(char('A' + c));
                prev = c;
                found = true;
                break;
            }

            freq[c]++;
        }

        if(!found){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}