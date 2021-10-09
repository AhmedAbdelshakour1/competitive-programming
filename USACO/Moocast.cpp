// http://www.usaco.org/index.php?page=viewproblem2&cpid=668

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
bool vis[201];
vector<int> adj[201];
vector<pair<pair<int, int>, int>> v(201);
int numberOfNodes, n;
 
void dfs(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(int j : adj[node]){
        if (!vis[j]) {
            numberOfNodes++;
            dfs(j);
        }
    }
}
int distance(int i, int j){
    return (v[i].first.first - v[j].first.first) * (v[i].first.first - v[j].first.first)
          +(v[i].first.second - v[j].first.second) * (v[i].first.second - v[j].first.second);
}
int main() {
    IO();
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i = 0; i< n; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
           if(distance(i, j)  <= v[i].second * v[i].second)
               adj[i].push_back(j);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        memset(vis, false, sizeof(vis));
        numberOfNodes = 1;
        dfs(i);
        res = max(res, numberOfNodes);
    }
    cout << res;
}
