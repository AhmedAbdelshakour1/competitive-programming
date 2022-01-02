// https://vjudge.net/problem/UVA-476

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
vector<pair<pair<pair<double, double> , pair<double, double>>, int>> v;
void check(double x, double y, int cnt){
    int f = 0;
    for (int i = 0; i < len(v); ++i) {
        if(dcomp(x , v[i].first.first.first) == -1 && dcomp(x , v[i].first.second.first) == 1 && dcomp(y , v[i].first.second.second) == -1 &&
                dcomp(y, v[i].first.first.second) == 1) {
            f = 1;
            cout << "Point " << cnt << " is contained in figure " << v[i].second << nline;
        }
    }
    if(!f) cout << "Point " << cnt << " is not contained in any figure" << nline;
}
int main() {
    char c;
    int curr = 0;
    while(cin >> c && c == 'r'){
        double xul, yul, xlr, ylr; cin >> xul >> yul >> xlr >> ylr;
        v.push_back({{{xul, yul}, {xlr, ylr}}, ++curr});
    }
    double x, y;
    int cp = 0;
    while(cin >> x >> y && x != 9999.9 && y != 9999.9){
        check(x, y, ++cp);
    }
}
