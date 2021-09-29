// https://cses.fi/problemset/task/1674/

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
int sz[N];
int dfs(int node, int parent){
    sz[node] = 1;
    for(int v : adj[node]){
        if(v != parent){
            sz[node] += dfs(v, node);
        }
    }
    return sz[node];
}
 
int main() {
    IO();
    cin >> n;
    for(int i = 2; i <= n; i++){
        int parent; cin >> parent;
        adj[i].push_back(parent);
        adj[parent].push_back(i);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++){
        cout << sz[i] - 1 << " " ;
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
