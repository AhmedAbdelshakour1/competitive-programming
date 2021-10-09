// http://www.usaco.org/index.php?page=viewproblem2&cpid=944

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
const int MAX = 1e5 + 1;
bool vis[MAX];
vector<int> adj[MAX];
vector<pair<pair<int, int>, int>> v(MAX);
int n, m, minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
void dfs(int node){
    if(vis[node]) return;
    vis[node] = true;
    maxX = max(v[v[node].second].first.first, maxX);
    minX = min(v[v[node].second].first.first, minX);
    maxY = max(v[v[node].second].first.second, maxY);
    minY = min(v[v[node].second].first.second, minY);
    for(int j : adj[node]){
        if(!vis[j]) {
            dfs(j);
        }
    }
}
int perimter(){
    return ((maxX - minX) + (maxY - minY)) * 2;
}
int main() {
    IO();
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = i;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    for(int node = 1; node <=n; node++) {
        minX = INT_MAX;
        minY = INT_MAX;
        maxX = INT_MIN;
        maxY = INT_MIN;
        if (!vis[node]) {
            dfs(node);
            ans = min(ans, perimter());
        }
    }
    cout << ans;
}
