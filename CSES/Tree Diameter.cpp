// https://cses.fi/problemset/task/1131/

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
int curNode, maxDis = -1;
void dfs(int node, int parent, int depth = 0){
    if(depth > maxDis){
        maxDis = depth;
        curNode = node;
    }
    for(int v : adj[node]){
        if(v != parent){
            dfs(v, node, depth + 1);
        }
    }
}
int main() {
    IO();
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    int maxNode = curNode;
    maxDis = -1;
    dfs(maxNode, maxNode);
    cout << maxDis << endl;
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
