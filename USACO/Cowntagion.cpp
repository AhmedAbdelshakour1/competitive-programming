// http://www.usaco.org/index.php?page=viewproblem2&cpid=1062

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
const int N = 1e5 + 1;
vector<int> adj[N];
int dfs(int node, int parent){
    int ans = 0, days = 0, currCows = 1;
    int cowsNeeded = adj[node].size();
    if(parent == -1) cowsNeeded++;
    while(currCows < cowsNeeded){
        days++;
        currCows *= 2;
    }
    ans += days;
    for(auto val : adj[node]){
        if(val != parent){
            ans += dfs(val, node) + 1;
        }
    }
    return ans;
}
int main() {
    //IO();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1, -1);
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
