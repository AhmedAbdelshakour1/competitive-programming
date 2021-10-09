// http://www.usaco.org/index.php?page=viewproblem2&cpid=644

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
bool vis[3001], closed[3001];
 vector<int> adj[3001];
int numberOfNode, n, m;
void dfs(int node){
    if(vis[node] || closed[node]) return;
    numberOfNode++;
    vis[node] = true;
    for (int j : adj[node]) {
        if (!vis[j]) {
            dfs(j);
        }
    }
}
int main() {
    IO();
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0 ;i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
    }
    dfs(0);
    if(numberOfNode == n) cout << "YES\n";
    else cout << "NO\n";
    vector<int> vertix(n);
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        v--;
        vertix[i] = v;
    }
    for(int i = 0; i < n - 1; i++){
        fill(vis, vis + n, false);
        numberOfNode = 0;
        closed[vertix[i]] = true;
        dfs(vertix[n - 1]);
        (numberOfNode == n - i - 1) ? cout << "YES\n" : cout << "NO\n";
    }
}
