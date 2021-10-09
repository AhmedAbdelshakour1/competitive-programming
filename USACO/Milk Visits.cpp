// http://www.usaco.org/index.php?page=viewproblem2&cpid=968

#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
const int N = 1e5 + 1;
vector<int> adj[N];
bool check[N];
int comp[N];
int currComp = 0;
void dfs(int node){
    if(comp[node]) return;
    comp[node] = currComp;
    for(auto val : adj[node]){
        if(check[val] == check[node])
            dfs(val);
    }
}
int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    for(int i = 0; i < s.size(); i++) check[i + 1] = s[i] == 'H';
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(comp[i]) continue;
        currComp++;
        dfs(i);
    }
    for(int i = 0; i < m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        if(comp[a] != comp[b] || (comp[a] == comp[b] && s[a - 1] == c)) cout << 1;
        else cout << 0;
    }
 
}
