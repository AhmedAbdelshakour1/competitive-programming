// https://cses.fi/problemset/task/1070/

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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const int INF = (int) 2e9 + 10;
const ll OO = 1e18;
const double eps = 1e-9;

void IO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
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

bool isPowerOfTwo(ll n) { return n && (!(n & (n - 1))); }


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
void solve() {
    int n; cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return;
    }
    for(int i = 2; i <= n; i += 2)  cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
}
int main() {
    IO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
