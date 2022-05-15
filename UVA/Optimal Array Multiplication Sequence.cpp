// https://vjudge.net/problem/UVA-348

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
        if (p & 1) result = (a % MOD * result % MOD) % MOD;
        a = (a % MOD * a % MOD) % MOD;;
        p >>= 1;
    }
    return result;
}

//.........................................(^_^)............................................//
int memo[11][11], posX[11][11];
int r[11], c[11];
int dp(int st, int end){
    if(st >= end) return 0;
    int &ret = memo[st][end];
    if(~ret) return ret;
    ret = 1 << 30;
    for (int i = st; i <= end; ++i) {
        int curr = dp(st, i) + dp(i + 1, end) + r[st] * c[i] * c[end];
        if(curr < ret){
            ret = curr;
            posX[st][end] = i;
        }
    }
    return ret;
}

void print(int st, int end){
    if(st == end) cout << "A" << st + 1;
    else {
        cout << "(";
        print(st, posX[st][end]);
        cout << " x ";
        print(posX[st][end] + 1, end);
        cout << ")";
    }
}
void solve(){
    int n, test = 1;
    while(cin >> n && n){
        for (int i = 0; i < n; ++i)
            cin >> r[i] >> c[i];
        memset(memo, -1, sizeof memo);
        memset(posX, 0, sizeof posX);
        dp(0, n - 1);
        cout << "Case " << test++ << ": ";
        print(0, n - 1);
        cout << nline;
    }
}
int main() {
    IO();
    int t = 1;
    //cin >> t;
    //while (t--) {
        solve();
    //}
}

