// https://atcoder.jp/contests/abc175/tasks/abc175_b?lang=en

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};
ll pow(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//
const int MOD = 1e9 + 7;
int check(ll a, ll b, ll c){
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    set<pair<pair<ll, ll>, ll>> st;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(v[i] == v[j]) continue;
            for (int k = j + 1; k < n; ++k) {
                if(v[k] == v[j] || v[k] == v[i]) continue;
                if(check(v[i], v[j], v[k])) st.insert({{i + 1, j + 1}, k + 1});
            }
        }
    }
    printf("%d", len(st));
}
