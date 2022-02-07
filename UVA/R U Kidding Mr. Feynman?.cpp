// https://vjudge.net/problem/UVA-10509

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

    /**
     n^1/3 = a + dx
     n = (a + dx)^3
     n = a^3 + 3*a^2*dx + 3*a*dx^2 + dx^3
     n = a^3 + 3*a^2*dx >> //ignore higher order dx terms
     -> n^1/3 = a + (n - a^3) / 3*a^2
     **/

    double n;
    while(scanf("%lf", &n) && n){
        int a = pow(n, 1.0 / 3.0) + 1e-6;
        printf("%.4f\n", a * 1.0 + ((n - a * a * a) * 1.0 / (3 * a * a)));
    }
}
