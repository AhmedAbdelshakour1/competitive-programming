// https://open.kattis.com/problems/birthday

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
bool vis[101];
int adj[101][101];
int numberOfNodes, n, m;
void dfs(int node){
    if(vis[node]) return;
    numberOfNodes++;
    vis[node] = true;
    for(int j = 0; j < n; j++){
        if (!vis[j] && adj[node][j]) {
            dfs(j);
        }
    }
}
int main() {
    IO();
    while(cin >> n >> m && (n || m)) {
        memset(adj, false, sizeof(adj));
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a][b] = true;
            adj[b][a] = true;
            edges[i] = {a, b};
        }
        bool flag = false;
        for(int i = 0; i < m; i++){
            memset(vis, false, sizeof(vis));
            adj[edges[i].first][edges[i].second] = false;
            adj[edges[i].second][edges[i].first] = false;
            numberOfNodes = 0;
            dfs(0);
            if(numberOfNodes != n){
                cout << "YES\n";
                flag = true;
                break;
            }
            adj[edges[i].first][edges[i].second] = true;
            adj[edges[i].second][edges[i].first] = true;
        }
        if(!flag)cout << "NO\n";
    }
}
