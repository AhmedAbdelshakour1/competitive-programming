// https://cses.fi/problemset/task/1192/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
#define INF 0x3f3f3f3f
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] {-1, 1, 0, 0};
int dy4[4] {-0, 0, -1, 1};
 
ll pow(int b, int p) {   // O(log(p) base 2)
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
const int N = 1e3 + 2;
int n, m;
char adj[N][N];
bool vis[N][N];
void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while(q.size()) {
        auto curr = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = curr.first + dx4[k];
            int y = curr.second + dy4[k];
            if (!vis[x][y] && x >= 0 && x < n && y >= 0 && y < m && adj[x][y] == '.') {
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
      for (int j = 0; j < m; ++j) {
          cin >> adj[i][j];
      }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
      for (int j = 0; j < m; ++j) {
          if(!vis[i][j] && adj[i][j] == '.'){
              ans++;
              bfs(i, j);
          }
      }
  }
  cout << ans << endl;
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
