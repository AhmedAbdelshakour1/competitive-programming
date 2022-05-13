// https://vjudge.net/problem/UVA-11753

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
const int N = 1e4 + 10;
int v[N], memo[N][21][21];
int n, k;
int dp(int i, int insRight, int insLeft){
    int j = n - 1 - i - insLeft + insRight;
    if(insRight + insLeft >k) return 30;
    if(i >= j) return 0;
    if(~memo[i][insRight][insLeft]) return memo[i][insRight][insLeft];

    if(v[i] == v[j]) return memo[i][insRight][insLeft] = dp(i + 1, insRight, insLeft);
    return memo[i][insRight][insLeft] = 1 + min(dp(i + 1, insRight + 1, insLeft), dp(i, insRight, insLeft + 1));
}
void solve() {
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> v[i];

        memset(memo, -1, sizeof memo);
        int ans = dp(0,0, 0);
        if (!ans) cout << "Case " << q << ": " << "Too easy\n";
        else if(ans > k) cout << "Case " << q << ": " << "Too difficult\n";
        else cout << "Case " << q << ": " << ans << nline;
    }
}
int main() {
    IO();
    solve();
}

