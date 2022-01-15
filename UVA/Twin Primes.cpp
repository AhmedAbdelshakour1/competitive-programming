https://vjudge.net/problem/UVA-10394

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
vector<bool> isPrimes(20000001, true);
vector<ll> primes;

void sieve() {
    isPrimes[0] = isPrimes[1] = false;
    for (int i = 2; i * i <= 20000000; ++i) {
        if (isPrimes[i]) {
            for (int j = i * 2; j <= 20000000; j += i) {
                isPrimes[j] = false;
            }
        }
    }
    for (int i = 0; i < len(isPrimes); ++i) {
        if (isPrimes[i]) primes.push_back(i);
    }
}

int main() {
    sieve();
    int n;
    int m = len(primes);
    vector<pair<ll, ll>> v;
    for (int i = 0; i < m - 1; ++i) {
        ll curr = primes[i];
        if (curr + 2 == primes[i + 1]) v.push_back({curr, curr + 2});
    }
    while(scanf("%d", &n) == 1) {
        printf("(%lld, %lld)\n", v[n - 1].first, v[n - 1].second);
    }
}
