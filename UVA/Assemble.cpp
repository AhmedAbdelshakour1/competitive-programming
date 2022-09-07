// https://vjudge.net/problem/UVA-12124#author=0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define nl '\n'
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
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

bool isVowel(char s) {
    s = tolower(s);
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
    return false;
}

ll toInt(string s) {
    ll r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}

string to_upper(string a) {
    for (int i = 0; i < (int) a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string a) {
    for (int i = 0; i < (int) a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
    return a;
}

string toString(ll number) {
    stringstream ss;
    ss << number;
    return ss.str();
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

template<class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x: v) cout << x << ","; cout << "\b}"; }

//.........................................(^_^)............................................//
vector<pair<string, pair<int, int>>> v;
int n, budget;
bool valid(int quality){
    ll sum = 0;
    int mn = INF;
    if(v[0].second.second >= quality) mn = v[0].second.first;
    for (int i = 1; i < n; ++i) {
        if(v[i].first != v[i - 1].first) sum += mn, mn = INF;
        if(v[i].second.second >= quality) mn = min(mn, v[i].second.first);
    }
    sum += mn;
    return sum <= budget;
}
int BS(){
    int st = 0, end = 1e9 + 10;
    while(st + 1 < end){
        int mid = st + end >> 1;
        if(valid(mid)) st = mid;
        else end = mid;
    }
    return st;
}
void solve(){
    cin >> n >> budget;
    for (int i = 0; i < n; ++i) {
        string a, b; int p, q; cin >> a >> b >> p >> q;
        v.push_back({a, {p, q}});
    }
    sort(all(v));
    cout << BS() << nl;
    v.clear();
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
