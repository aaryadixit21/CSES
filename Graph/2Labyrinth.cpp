#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
#define endl '\n'

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, ' '));

    pll A, B;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') A = {i, j};
            if (grid[i][j] == 'B') B = {i, j};
        }
    }

    queue<pll> q;
    q.push(A);
    vis[A.first][A.second] = true;

    bool found = false;
    while (!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if (x == B.first && y == B.second) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dr[k];
            int ny = y + dc[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                moveDir[nx][ny] = dir[k];
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        string path;
        pll cur = B;
        while (cur != A) {
            path.push_back(moveDir[cur.first][cur.second]);
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());

        cout<<path.size()<<endl;
        cout<<path<<endl;
    }

    return 0;
}
