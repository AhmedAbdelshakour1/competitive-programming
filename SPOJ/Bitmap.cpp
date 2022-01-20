// https://www.spoj.com/problems/BITMAP/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll pw(ll a, ll p) {
    if (p == 0) return 1;
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.....................................................................................//
vector<vector<int>> mat, dist;
int n, m;
bool valid(int a, int b){
    return a >= 0 && a < n && b >= 0 && b < m;
}
void bfs(){
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(mat[i][j]){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = curr.first + dx4[i];
            int y = curr.second + dy4[i];
            if(valid(x, y) && dist[x][y] == -1){
                q.push({x, y});
                dist[x][y] = dist[curr.first][curr.second] + 1;
            }
        }
    }
}
int main() {
    IO();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mat.assign(n, vector<int> (m));
        dist.assign(n, vector<int> (m, -1));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                mat[i][j] = s[j] - '0';
            }
        }
        bfs();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dist[i][j] << " \n"[j == m - 1];
            }
        }
    }
}
