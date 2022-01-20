// https://vjudge.net/problem/UVA-10843

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
ll m = 2000000011;
ll pw(ll a, ll p) {
    if (p == 0) return 1;
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = (result % m * a % m) % m;
        a = (a % m * a % m) % m;
        p >>= 1;
    }
    return result % m;
}

//.....................................................................................//

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        if(n == 1 || n == 0){
            printf("Case #%d: %d\n", i, n == 1);
        }else{
            printf("Case #%d: %d\n", i, pw(n, n - 2));
        }
    }
}
