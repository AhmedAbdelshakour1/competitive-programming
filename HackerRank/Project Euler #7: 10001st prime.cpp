// https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem?fbclid=IwAR3uYhEMM2pg3UEKF5_YenHdwUpHf29OAq-mA4sTK4HDHAstv23H_VtjHBY

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;

#define nl '\n'
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const int INF = (int) 2e9 + 10;
const ll OO = 1e18;
const double eps = 1e-9;


int dcomp(double a, double b) { return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1; }

bool isPowerOfTwo(ll n) { return n && (!(n & (n - 1))); }


ll bPow(ll a, ll p) {
    ll result = 1;
    while (p) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//....................................My success is only by Allah....................................//
int N = 5e5 + 1;
vector<ll> primes;
void sieve(){
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= N; ++i) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= N; j += i)
                isPrime[j] = 0;
        }
    }

    for (int i = 0; i < (int)isPrime.size(); ++i)
        if(isPrime[i])
            primes.push_back(i);

}
void solve() {
    int n; cin >>  n;
    cout <<  primes[n - 1] << nl;
}

int main() {
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}


