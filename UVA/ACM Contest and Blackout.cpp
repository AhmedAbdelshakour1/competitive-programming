// https://vjudge.net/problem/UVA-10600

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
const ll OO = 1e8;


ll pw(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pw(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//

struct unionFind{
    vector<int> rank, parent;

    unionFind(int n) {
        rank.resize(n,0);
        parent.resize(n);
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

struct edge{
    int from, to, w, index;
    bool rem;
    edge(int from, int to, int w, int index): from(from), to(to), w(w), index(index), rem(false){}
    bool operator < (const edge & ed) const {
        return w > ed.w;
    }
};

pair<int, vector<edge>> kruskalMST(vector<edge> edgeList, int n){
    unionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> q;
    for (int i = 0; i < len(edgeList); ++i) {
        if(!edgeList[i].rem)
        q.push(edgeList[i]);
    }

    while(!q.empty()){
        edge ed = q.top();
        q.pop();
        if(uf.unionSets(ed.from, ed.to)){
            mstCost += ed.w;
            edges.push_back(ed);
        }
    }
    if(len(edges) != n - 1) return make_pair(OO, vector<edge>());
    return make_pair(mstCost, edges);

}
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m; scanf("%d %d", &n, &m);
        vector<edge> v;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            v.push_back(edge(a, b, c, i));
        }
        pair<int, vector<edge>> ans = kruskalMST(v, n);
        int secondCostMST = MOD, sz = len(ans.second);
        for (int i = 0; i < sz; ++i) {
            v[ans.second[i].index].rem = true;
            pair<int, vector<edge>> ans2 = kruskalMST(v, n);
            secondCostMST = (ans2.first < secondCostMST) ? ans2.first : secondCostMST;
            v[ans.second[i].index].rem = false;
        }
        printf("%d %d\n", ans.first, secondCostMST);
    }
}
