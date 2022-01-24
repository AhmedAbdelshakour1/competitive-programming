// https://vjudge.net/problem/UVA-498

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
vector<ll> convert(string s){
    vector<ll> a;
    int f = 0;
    for (int i = 0; i < len(s); i++){
        if(s[i] == '-') {
            f = 1;
            continue;
        }
        if(s[i] != ' ') {
            if(f) {
                int curr = 0;
                while (s[i] != ' ' && i < len(s)) {
                    curr = curr * 10 + (s[i] - '0');
                    i++;
                }
                a.push_back(-curr);
            }else {
                int curr = 0;
                while (s[i] != ' ' && i < len(s)) {
                    curr = curr * 10 + (s[i] - '0');
                    i++;
                }
                a.push_back(curr);
            }
            f = 0;
        }
    }
    return a;
}
int main() {
    while(1){
        string t, s;
        getline(cin, s);
        getline(cin, t);
        if(s.empty()) break;
        vector<ll> a = convert(s);
        vector<ll> b = convert(t);
        int n = len(a) - 1;
        for (int k = 0; k < len(b); ++k) {
            ll ans = 0;
            int curr = n;
            for (int i = 0; i <= n; ++i) {
                ans += a[i] * pw(b[k], curr);
                curr--;
            }
            cout << ans << " \n"[k == len(b) - 1];
        }

    }
}
