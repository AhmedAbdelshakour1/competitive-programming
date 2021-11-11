// https://vjudge.net/problem/UVA-11094

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};

ll pow(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//
const int MOD = 1e9 + 7;
int n, m;
char grid[30][30];
int vis[30][30];
int cnt;
char ch;
bool valid(int x) { return x >= 0 && x < n; }
int valid_y(int y){
    if (y < 0) return m - 1;
    if (y >= m) return 0;
    return y;
}
void dfs(int i , int j){
    vis[i][j] = 1;
    cnt++;
    for(int k = 0; k < 4; k++){
        int move_x = i + dx4[k];
        int move_y = valid_y(j + dy4[k]);
        if(valid(move_x) && !vis[move_x][move_y] && grid[move_x][move_y] == ch)
            dfs(move_x, move_y);
    }
}

int main() {
    IO();
    while (cin >> n >> m) {

        memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        int x, y;
        cin >> x >> y;
        ch = grid[x][y];
        dfs(x, y);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == ch) {
                    cnt = 0;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << nline;
    }
}

/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/
