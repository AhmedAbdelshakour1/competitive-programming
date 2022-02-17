// https://vjudge.net/problem/UVA-10490

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
vector<ll> div(ll n){
    vector<ll> ans;
    ans.push_back(1);
    ll i;
    for (i = 2; i * i < n; ++i) {
        if(n % i == 0) ans.push_back(i), ans.push_back(n / i);
    }
    if(i * i == n) ans.push_back(i);
    ans.push_back(n);
    return ans;
}
int main() {
    ll n;
    while (scanf("%lld", &n) && n) {
        ll p = pw(2, n - 1);
        ll p2 = (pw(2, n) - 1);
        auto dv1 = div(p);
        auto dv2 = div(p2);
        auto check = div(n);
        ll ans = 0;
        for (int i = 0; i < len(dv1); ++i)
            for (int j = 0; j < len(dv2); ++j)
                ans += dv1[i] * dv2[j];
        ans -= (p * p2);
        if (ans == (p * p2)) {
            printf("Perfect: %lld!\n", ans);
        } else {
            if (len(check) == 2)
                puts("Given number is prime. But, NO perfect number is available.");
            else puts("Given number is NOT prime! NO perfect number is available.");
        }
    }
}
