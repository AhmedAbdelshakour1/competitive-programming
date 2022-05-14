// https://vjudge.net/problem/UVA-10003

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
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.........................................(^_^)............................................//
int l, n;
int v[55], memo[55][55];
int dp(int st, int end, int stIndx, int endIndx){
    if(st >= end || stIndx > endIndx) return 0;
    if(~memo[stIndx][endIndx]) return memo[stIndx][endIndx];
    int ans = MOD;
    for (int i = stIndx; i <= endIndx; ++i) {
        int cutPlace = v[i];
        ans = min(ans, dp(st, cutPlace, stIndx, i - 1) + dp(cutPlace + 1, end, i + 1, endIndx) + (end - st + 1));
    }
    return memo[stIndx][endIndx] = ans;
}
void solve() {
    while(cin >> l && l){
        memset(memo, -1, sizeof memo);
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> v[i];
        cout << "The minimum cutting is " << dp(1, l, 0, n - 1) << "." << nline;
    }
}
int main() {
    IO();
    solve();
}

