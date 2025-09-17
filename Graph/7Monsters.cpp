#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define take(arr, n) \
    vector<ll> arr(n); \
    for(auto &it : arr) cin >> it
const ll M = 1000000007;
#define le(x) \
    ll x; \
    cin >> x
#define dikha(a) cout << a << endl

//---------------------------------/
string abc = "abcdefghijklmnopqrstuvwxyz";
const ll N = 100005;
int dp[1000005];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<char> mapping = {'U', 'D', 'L', 'R'};
//---------------------------------/

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    le(n); le(m);
    vector<vector<char>> grid(n, vector<char>(m));
    queue<pair<int,int>> monsters;
    pair<int,int> start;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'M') monsters.push({i,j});
        }
    }

    const int INF = 1e9;
    vector<vector<int>> monster_time(n, vector<int>(m, INF));
    vector<vector<int>> player_time(n, vector<int>(m, INF));
    vector<vector<char>> dir(n, vector<char>(m, '-'));

    queue<pair<int,int>> q;
    while(!monsters.empty()){
        pair<int,int> p = monsters.front(); monsters.pop();
        monster_time[p.first][p.second] = 0;
        q.push(p);
    }
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for(int k=0;k<4;k++){
            int nx = x+dr[k], ny = y+dc[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' 
               && monster_time[nx][ny] == INF){
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    queue<pair<int,int>> qp;
    qp.push(start);
    player_time[start.first][start.second] = 0;
    bool possible = false;
    pair<int,int> end = {-1,-1};

    while(!qp.empty()){
        pair<int,int> cur = qp.front(); qp.pop();
        int i = cur.first, j = cur.second;

        if(i==0 || i==n-1 || j==0 || j==m-1){
            possible = true;
            end = {i,j};
            break;
        }
        for(int k=0;k<4;k++){
            int ni = i+dr[k], nj = j+dc[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.'){
                if(player_time[ni][nj] == INF && 
                   player_time[i][j]+1 < monster_time[ni][nj]){
                    player_time[ni][nj] = player_time[i][j] + 1;
                    dir[ni][nj] = mapping[k];
                    qp.push({ni,nj});
                }
            }
        }
    }

    if(!possible){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<char> path;
    int i = end.first, j = end.second;
    while(grid[i][j] != 'A'){
        char d = dir[i][j];
        path.push_back(d);
        if(d == 'U') i++;
        else if(d == 'D') i--;
        else if(d == 'L') j++;
        else if(d == 'R') j--;
    }
    reverse(all(path));
    cout << path.size() << "\n";
    for(char c : path) cout << c;
    cout << "\n";
}