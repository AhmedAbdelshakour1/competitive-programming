// http://www.usaco.org/index.php?page=viewproblem2&cpid=788

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n, q, k, val, sol = 0;
vector<pair<int, int>> v[5001];
vector<bool> vis(5001);
void dfs(int &node){
    vis[node] = true;
    for(auto &vid : v[node]){
        if(vis[vid.first]) continue;
        if(vid.second >= k){
            sol++;
            dfs(vid.first);
        }
    }
}
int main(){
    IO();
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int a, b, r; cin >> a >> b >> r;
        v[a].push_back({b, r});
        v[b].push_back({a, r});
    }
    for(int i = 0; i < q; i++){
        cin >> k >> val;
        sol = 0;
        fill(vis.begin(), vis.begin() + n + 1, false);
        dfs(val);
        cout << sol << endl;
    }
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
