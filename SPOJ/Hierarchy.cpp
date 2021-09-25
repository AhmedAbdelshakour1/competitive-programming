// https://www.spoj.com/problems/MAKETREE/

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
 
const int NUM = 1e5 + 5;
vector<vector<int> > adj(NUM);
vector<int> order, boss(NUM);
bool vis[NUM];
 
void dfs(int node) {
    vis[node] = true;
    for (int child : adj[node]) {
        if (!vis[child])
            dfs(child);
    }
    order.push_back(node);
}
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        int a;
        scanf("%d", &a);
        for (int j = 1; j <= a; j++) {
            int b;
            scanf("%d", &b);
            adj[i].push_back(b);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    //6 2 7 1 4 5
    int curr = 0;
    for(int i = n - 1; i >= 0; i--){
        boss[order[i]] = curr;
        curr = order[i];
    }
    for (int i = 1; i <= n; i++) {
      cout << boss[i] << endl;
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
