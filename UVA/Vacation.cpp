// https://vjudge.net/problem/UVA-10192

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
string s, t;
int memo[105][105];
int LCS(int i, int j){
    if(i == len(s) || j == len(t))
        return 0;
    int &ret = memo[i][j];
    if(~ret) return ret;
    if(s[i] == t[j])
        return ret = LCS(i + 1, j + 1) + 1;
    return ret = max(LCS(i, j + 1), LCS(i + 1, j));
}
int main() {
    int test = 1;
    while(getline(cin, s) && s != "#"){
        getline(cin, t);
        memset(memo, -1, sizeof memo);
        cout << "Case #" << test << ": you can visit at most " << LCS(0, 0) << " cities." << nline;
        test++;
    }
}
