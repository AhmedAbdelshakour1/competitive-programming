// https://vjudge.net/problem/UVA-460

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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int xl1, yl1, xu1, yu1, xl2, yl2, xu2, yu2;
        scanf("%d %d %d %d %d %d %d %d", &xl1, &yl1, &xu1, &yu1, &xl2, &yl2, &xu2, &yu2);
        if(max(xl1, xl2) < min(xu1, xu2) && max(yl1, yl2) < min(yu1, yu2)) printf("%d %d %d %d\n", max(xl1, xl2), max(yl1, yl2), min(xu1, xu2), min(yu1, yu2));
        else puts("No Overlap");
        if(t) puts("");
    }
}
