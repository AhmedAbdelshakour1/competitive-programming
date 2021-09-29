// https://cses.fi/problemset/task/1132/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int N = 2e5 + 1;
int n;
vector<int> adj[N];
int dis[2][N];
int CurrNode, maxDis = -1;
void dfs(int node, int parent,int depth, int curr) {
    dis[curr][node] = depth;
   if(depth > maxDis){
       maxDis = depth;
       CurrNode = node;
   }
   for(int i : adj[node]){
       if(i != parent)
           dfs(i , node, depth + 1, curr);
   }
}
 
int main() {
    IO();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 0, 0);
    maxDis = -1;
    dfs(CurrNode, CurrNode, 0, 0);
    dfs(CurrNode, CurrNode, 0, 1);
    for(int i = 1; i <= n; i++)
        cout << max(dis[0][i], dis[1][i]) << " ";
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
