// https://vjudge.net/problem/UVA-193

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

bool powerOfTwo(int n) {
    return n && (!(n & (n - 1)));
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll pw(ll a, ll p) {
    if (p == 0) return 1;
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.....................................................................................//
vector<vector<int>> adj;
vector<int> best, curr;
vector<int> currColor;
int n, m;
bool canBeBlack(int node){
    for(int child : adj[node]){
        if(currColor[child]) return false;
    }
    return true;
}
void backTracking(int currNode){
    if(currNode == n){
        if(len(curr) > len(best)){
            best = curr;
        }
        return;
    }
    int maxPossibleBlacks = n - currNode;
    if(maxPossibleBlacks + len(curr) <= len(best)) return; //pruning
    if(canBeBlack(currNode)){
        currColor[currNode] = 1;
        curr.push_back(currNode);
        backTracking(currNode + 1);
        curr.pop_back();
        currColor[currNode] = 0;
    }
    backTracking(currNode + 1);
}

//aviod big search tree
void backTracking2(int currNode){
    if(currNode == n){
        if(len(curr) > len(best)){
            best = curr;
        }
        return;
    }
    int maxPossibleBlacks = n - currNode;
    if(maxPossibleBlacks + len(curr) <= len(best)) return; //pruning
    for (int i = currNode; i < n; ++i) {
        if (canBeBlack(i)) {
            currColor[i] = 1;
            curr.push_back(i);
            backTracking(i + 1);
            curr.pop_back();
            currColor[i] = 0;
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        adj.clear();
        adj.resize(n);
        best.clear();
        curr.clear();
        currColor.resize(n, 0);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        backTracking2(0);
        printf("%d\n", len(best));
        for (int i = 0; i < len(best); ++i) {
            if(!i) printf("%d", best[i] + 1);
            else printf(" %d", best[i] + 1);
        }
        puts("");
    }
}
