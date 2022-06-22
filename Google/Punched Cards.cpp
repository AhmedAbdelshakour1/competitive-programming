// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b

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
int main() {
    int t; cin >> t;
    for (int k = 1; k <= t; ++k) {
        int r, c; cin >> r >> c;
        r = r * 2 + 1;
        c = c * 2 + 1;
        vector<vector<char>> v(r, vector<char>(c));
        int f = 1;
        for (int i = 0; i < r; i++) {
            if(!(i & 1)) f = 1;
            for (int j = (i > 1 ? 0 : 2); j < c; ++j) {
                if ((i & 1) && !(j & 1)) {
                    v[i][j] = '|';
                } else if(!(i & 1)){
                    if (f == 1) v[i][j] = '+', f *= -1;
                    else v[i][j] = '-', f *= -1;
                }
            }
        }
        cout << "Case #" << k<< ":" << nline;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if(!v[i][j]){
                    cout << ".";
                    continue;
                }
                cout << v[i][j];
            }
            cout << nline;
        }
    }
}
