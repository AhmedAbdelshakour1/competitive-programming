https://vjudge.net/problem/UVA-1174

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
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

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
struct edge{
    int from, to, cost;
    edge(int from, int to, int c): from(from), to(to), cost(c) {};
    bool operator< (const edge &d) const{
        return d.cost < cost;
    }
};
vector<edge> v;
struct dsu{
    vector<int> rank, parent;

    dsu(int n) {
        rank.resize(n,0);
        parent.resize(n + 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findSet(int x){
        if(parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x, int y) {
        if(rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
    bool unionSets(int x, int y) {
        int parentX = findSet(x), parentY = findSet(y);
        if(parentX != parentY){
            link(parentX,parentY);
            return true;
        }
        return false;
    }

};
int kruskal(int sz){
    dsu dsuuu(sz);
    int mstCost = 0;
    priority_queue<edge> q;
    for (int i = 0; i < len(v); ++i) q.push(v[i]);
    while(!q.empty()){
        edge curr = q.top();
        q.pop();
        if(dsuuu.unionSets(curr.from, curr.to)){
            mstCost += curr.cost;
        }
    }
    return mstCost;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        v.clear();
        int n, m;
        cin >> n >> m;
        map<string, int> convert;
        int id = 0;
        while(m--){
            string a, b; int c;
            cin >> a >> b >> c;
            if(!convert[a]) convert[a] = ++id;
            if(!convert[b]) convert[b] = ++id;
            v.push_back(edge(convert[a], convert[b], c));
        }
        cout << kruskal(n) << nline;
        if(t) cout << nline;
    }
}
