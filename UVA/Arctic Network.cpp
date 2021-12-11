// https://vjudge.net/problem/UVA-10369

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
int xx[100000 + 1], yy[100000 + 10];

struct unionFind {
    vector<int> rank, parent;
    int forests;

    unionFind(int n) {
        rank = vector<int>(n), parent = vector<int>(n);
        forests = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findSet(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findSet(parent[x]);
    }

    void link(int x, int y) {
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }

    bool unionSets(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x != y;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, n;
        scanf("%d %d", &s, &n);
        for (int i = 0; i < n; ++i) scanf("%d %d", &xx[i], &yy[i]);

        unionFind d(n);
        vector<pair<double, pair<int, int>>> v;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dis = hypot(1.0 * (xx[i] - xx[j]), 1.0 * (yy[i] - yy[j]));
                v.push_back({dis, {i, j}});
            }
        }
        sort(all(v));
        //cout << len(v) << nline;
        double ans = 0.0;
        vector<pair<double, pair<int, int>>> res;
        for (int i = 0; i < len(v); ++i) {
            if (d.unionSets(v[i].second.first, v[i].second.second)) {
                d.unionSets(v[i].second.first, v[i].second.second);

                res.push_back({v[i].first, {v[i].second.first, v[i].second.second}});
            }
        }
        printf("%.2f\n", res[(n - 1) - s].first);
    }
}
