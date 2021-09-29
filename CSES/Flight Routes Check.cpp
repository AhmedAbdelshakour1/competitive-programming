// https://cses.fi/problemset/task/1682/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int MAX = 1e5 + 5;
bool vis[MAX];
vector<int> adj[MAX], adj2[MAX];
int n, m;
 
void dfs(int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (int j : adj[node]) {
        if (!vis[j]) {
            dfs(j);
        }
    }
}
void dfs2(int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (int j : adj2[node]) {
        if (!vis[j]) {
            dfs2(j);
        }
    }
}
 
int can() {
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            return i + 1;
    }
    return 0;
}
 
int main() {
    IO();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs(0);
    if (can() != 0) {
        cout << "NO\n" << "1 " << can();
        return 0;
    }
    memset(vis, false, sizeof(vis));
    dfs2(0);
    if (can() != 0) {
        cout << "NO\n" << can() << " " << 1;
    } else cout << "YES";
}
