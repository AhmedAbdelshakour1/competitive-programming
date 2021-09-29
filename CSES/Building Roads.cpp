// https://cses.fi/problemset/task/1666/

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
const int N = 1e5 + 2;
int n, m;
vector<int> adj[N];
bool vis[N];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(q.size()) {
        int node = q.front(); q.pop();
        for (int child: adj[node]) {
            if (!vis[child]){
                vis[child] = true;
                q.push(child);
            }
        }
    }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  vector<int> ans;
  for(int i = 1; i <= n; i++){
      if(!vis[i]){
          ans.push_back(i);
          bfs(i);
      }
  }
  cout << ans.size() - 1<< endl;
  for(int i = 0; i < len(ans) - 1; i++)
      cout << ans[i] << " " << ans[i + 1] << endl;
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