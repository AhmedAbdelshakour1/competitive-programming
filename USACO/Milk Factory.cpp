// http://www.usaco.org/index.php?page=viewproblem2&cpid=940

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef long long ll;
 
vector<int> adj[101];
vector<bool> vis(101);
int n;
void dfs(int node){
    vis[node] = true;
    for(int u : adj[node]){
        if(!vis[u])
            dfs(u);
    }
}
bool AllVis(){
    for(int i = 1; i <= n; i++){
        if(!vis[i]) return false;
    }
    return true;
}
int main() {
    IO();
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        fill(begin(vis), end(vis), false);
        dfs(i);
        if(AllVis()){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
