// https://cses.fi/problemset/task/1133/

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
ll sz[N], dis[N];
void dfs(int node, int parent, int depth = 0){
    dis[1] += depth;
    sz[node] = 1;
    for(int child : adj[node]){
        if(child != parent) {
            dfs(child, node, depth + 1);
            sz[node] += sz[child];
        }
    }
}
void dfs2(int node, int parent){
    for(int child : adj[node]){
        if(child != parent) {
            //dis[child] = dis[node] - sz[child] - dis[child] + n - sz[child] + dis[child];
            dis[child] = dis[node] + n - 2 * sz[child];
            dfs2(child, node);
        }
    }
}
int main() {
    //IO();
   scanf("%d", &n);
   for(int i = 1; i < n;i++){
       int a, b; scanf("%d %d", &a, &b);
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
   dfs(1, 1);
   dfs2(1, 1);
   for(int i = 1; i <= n; i++)
       cout << dis[i] << " ";
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
