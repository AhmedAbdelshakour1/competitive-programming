// https://vjudge.net/problem/UVA-10305

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
vector<vector<int> > adj(150);
deque<int> order;
bool vis[150];
 
void dfs(int node) {
    vis[node] = true;
    for (int child : adj[node]) {
        if (!vis[child])
            dfs(child);
    }
    order.push_front(node);
}
 
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && n) {
        adj.clear();
        order.clear();
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        for (int i = 0; i < n; i++)
            cout << order[i] << " \n"[i == (int) order.size() - 1];
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
