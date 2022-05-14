// https://vjudge.net/problem/UVA-10617

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
string s;
ll memo[66][66];
int n;

ll dp(int st, int end) {
    if(st == end) return 1;
    if(end - st + 1 == 2) return 2 + (s[st] == s[end]);
    ll &ret = memo[st][end];
    if (~ret) return ret;
    ll ans = 0;
    if(s[st] == s[end]) ans +=  1 + dp(st + 1, end - 1); // because s[st] = s[end] so two characters is palindrome eg(AA)
    ans += dp(st + 1, end);
    ans += dp(st, end - 1);
    ans -= dp(st + 1, end - 1);
    return ret = ans;
}

void solve() {
    cin >> s;
    n = len(s);
    memset(memo, -1, sizeof memo);
    cout << dp(0, n - 1) << nline;
}

int main() {
    IO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

