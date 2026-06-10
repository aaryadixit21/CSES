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

void func(int n, string &s, vector<int> &freq){
    if(s.length() == n){
        cout << s << endl;
        return;
    }
    for(int i=0; i<26; ++i){
        if(freq[i] > 0){
            s += (char)('a' + i);
            freq[i]--;
            func(n, s, freq);
            freq[i]++;
            s.pop_back();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    long long n=s.size();
    vector<int> freq(26,0);
    for(long long i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    long long cnt=1;
    for(long long i{n}; i>0; --i){
        cnt*=i;
    }
    for(long long i=0;i<26;i++){
        for(long long j=0;j<freq[i];j++){
            cnt/=j+1;
        }
    }
    cout<<cnt<<endl;
    string ans="";
    func(n, ans, freq);
}