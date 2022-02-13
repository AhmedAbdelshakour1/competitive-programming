// https://vjudge.net/problem/UVA-750

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
vector<int> queenCol(8);
int visCol[8], rightD[17], leftD[17];
int a, b;
set<vector<int>> ans;

void eightQueens(int r) {
    if (r == 8) {
        if(queenCol[b] == a)
        ans.insert(queenCol);
        return;
    }
    for (int col = 0; col < 8; ++col) {
        if (!visCol[col] && !rightD[r + col] && !leftD[col - r + 8]) {
            queenCol[col] = r;
            visCol[col] = rightD[r + col] = leftD[col - r + 8] = 1;
            eightQueens(r + 1);
            visCol[col] = rightD[r + col] = leftD[col - r + 8] = 0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        a--, b--;
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");
        queenCol[b] = a;
        eightQueens(0);
        int i = 1;
        for (auto x: ans) {
            printf("%2d     ", i++);
            for (int j = 0; j < len(x); ++j) {
                printf(" %d", x[j] + 1);
            }
            puts("");
        }
        if(t) puts("");
        ans.clear();
    }
}
