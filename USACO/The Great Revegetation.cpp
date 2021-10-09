// http://www.usaco.org/index.php?page=viewproblem2&cpid=916

#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[101], seeds(101);
bool valid(int g, int pasture){
    for(int node : adj[pasture]){
        if(seeds[node] == g) return false;
    }
    return true;
}
int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        for(int g = 1; g <= 4; g++){
            if(valid(g, i)) {
                seeds[i] = g;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << seeds[i];
}
