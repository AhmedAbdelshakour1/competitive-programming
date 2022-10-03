// https://www.spoj.com/problems/PRIME1/

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define nl '\n'
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const int INF = (int) 2e9 + 10;
const ll OO = 1e18;
const double eps = 1e-9;

ll toInt(string s) {
    ll r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}

string toString(ll number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

string to_upper(string a) {
    for (char &i : a) if (i >= 'a' && i <= 'z') i -= 'a' - 'A';
    return a;
}

string to_lower(string a) {
    for (char &i : a) if (i >= 'A' && i <= 'Z') i += 'a' - 'A';
    return a;
}

int dcomp(double a, double b) { return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1; }

bool powerOfTwo(ll n) { return n && (!(n & (n - 1))); }


ll binPow(ll a, ll p) {
    ll result = 1;
    while (p) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.........................................\ (•◡•) /............................................//
vector<char> segmentedSieve(int L, int R){
    int sq = sqrt(R);
    vector<char> vis(sq + 1, true);
    vector<ll> isPrime;
    for (ll i = 2; i <= sq; ++i) {
        if(vis[i]){
            isPrime.push_back(i);
            for (ll j = i * i; j <= sq; j += i) vis[j] = 0;
        }
    }
    vector<char> primes(R - L + 1, true);
    for(auto p : isPrime){
        for (ll i = max(p * p, (L + p - 1) / p * p); i <= R; i += p) primes[i - L] = 0;
    }
    if(L == 1) primes[0] = 0;
    return primes;
}
void solve() {
    int l, r; cin >> l >> r;
    auto ans = segmentedSieve(l, r);
    for (int i = 0; i < len(ans); ++i) {
        if(ans[i]) cout << l + i << nl;
    }
    cout << nl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    IO
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
