// https://cses.fi/problemset/task/1667/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
#define INF 0x3f3f3f3f
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
ll pow(int b, int p) {   // O(log(p) base 2)
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N];
int pre[N];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(q.size()){
        int node = q.front(); q.pop();
        for(int child : adj[node]){
            if(!vis[child]){
                q.push(child);
                pre[child] = node;
                vis[child] = true;
            }
        }
    }
    if(vis[n]){
        deque<int> path;
        int curr = n;
        while(curr != 1){
            path.push_front(curr);
            curr = pre[curr];
        }
        path.push_front(1);
        printf("%d\n", len(path));
        for(int i : path)
            printf("%d ", i);
    }else puts("IMPOSSIBLE");
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
