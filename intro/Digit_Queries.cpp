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
    
    long long q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        long long i=1;
        long long x=1;
        bool done=false;
        while(!done){
            long long cnt= 9*x*i;
            if(k>cnt){
                k-=cnt;
                i++;
                x*=10;
            }
            else{
                done=true;
            }
        }
        if(i==1){
            cout<<k<<endl;
            continue;
        }
        long long newk = k/i;
        long long rem = k%i;
        long long ans = x -1 + newk;
        if(rem==0) cout<<ans%10<<endl;
        if(rem!=0) {
            ans++;
            string s = to_string(ans);
            cout<<s[rem-1]<<endl;
        }    
    }    
}