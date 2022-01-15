// https://vjudge.net/problem/UVA-10168

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
int sz = 20000000;
vector<bool> isPrime(sz + 1, true);
vector<ll> primes;
void sieve(){
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= sz; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= sz; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 0; i < sz; ++i)
        if(isPrime[i]) primes.push_back(i);
}
int main() {
    sieve();
    int m = len(primes);
    int n;
    while(scanf("%d", &n) == 1) {
        if (n < 8) {
            puts("Impossible.");
            continue;
        }
        if (n & 1) {
            n -= 5;
            for (int i = 0; i < m; ++i) {
                if (isPrime[n - primes[i]]) {
                    printf("%lld %lld %lld %lld\n", 2, 3, primes[i], n - primes[i]);
                    break;
                }
            }
        } else {
            n -= 4;
            for (int i = 0; i < m; ++i) {
                if (isPrime[n - primes[i]]) {
                    printf("%lld %lld %lld %lld\n", 2, 2, primes[i], n - primes[i]);
                    break;
                }
            }
        }
    }
}
