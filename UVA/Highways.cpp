// https://vjudge.net/problem/UVA-10147

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

struct unionFind {
    vector<int> rank, parent;
    int forests;

    unionFind(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        forests = n;
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findSet(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }

    void link(int x, int y) {
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }

    bool unionSets(int x, int y) {
        int parentX = findSet(x), parentY = findSet(y);
        if (parentX != parentY) {
            link(parentX, parentY);
            forests--;
        }
        return parentX != parentY;
    }

    int same_set(int x, int y) {
        return findSet(x) == findSet(y);
    }
};

struct edge {
    int from, to;
    double w;

    edge(int from, int to, double w) : from(from), to(to), w(w) {}

    bool operator<(const edge &ed) const {
        return w > ed.w;
    }
};


int cx[750], cy[750];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        unionFind uf(n);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            cx[i] = x;
            cy[i] = y;
        }
        vector<pair<double, pair<int, int>>> curr;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = hypot((double) (cx[i] - cx[j]), (double) (cy[i] - cy[j]));
                curr.push_back({dist, {i, j}});
            }
        }
        sort(all(curr));
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            uf.unionSets(a, b);
        }
        int f = 0;
        for (int i = 0; i < len(curr) && uf.forests > 1; ++i) {
            if (!uf.same_set(curr[i].second.first, curr[i].second.second)) {
                f = 1;
                printf("%d %d\n", curr[i].second.first + 1, curr[i].second.second + 1);
                uf.unionSets(curr[i].second.first, curr[i].second.second);
            }
        }
        if (!f) printf("No new highways need\n");
        if (t) printf("\n");
    }
}
