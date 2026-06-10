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
bool isValid(int i, int j, vector<vector<char>>& board){
    if(board[i][j]=='*') return false;
    for(int k=0; k<8; ++k){
        if(board[i][k]=='Q') return false;
        if(board[k][j]=='Q') return false;
    }
    for(int k=0; k<8; ++k){
        if(i+k<8 && j+k<8 && board[i+k][j+k]=='Q') return false;
        if(i-k>=0 && j-k>=0 && board[i-k][j-k]=='Q') return false;
        if(i+k<8 && j-k>=0 && board[i+k][j-k]=='Q') return false;
        if(i-k>=0 && j+k<8 && board[i-k][j+k]=='Q') return false;
    }
    return true;
}

int func(int i, vector<vector<char>>& board){
    if(i==8) return 1;
    int ans=0;
    for(int j=0; j<8; ++j){
        if(isValid(i, j, board)){
            board[i][j]='Q';
            ans+=func(i+1, board);
            board[i][j]='.';
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<char>> board(8, vector<char>(8));
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            cin >> board[i][j];
        }
    }
    cout << func(0, board) << endl;
}