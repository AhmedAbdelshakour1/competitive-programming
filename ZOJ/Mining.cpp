// https://zoj.pintia.cn/problem-sets/91827364500/problems/91827364699

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nl '\n';
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

string toString(ll number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

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

ll pw(ll a, ll p, int m) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = (a % m * result % m) % m;
        a = (a % m * a % m) % m;;
        p >>= 1;
    }
    return result % m;
}

//.........................................(^_^)............................................//

int main(){
    IO();
    ll s, w, c, k, m;
    while(cin >> s >> w >> c >> k >> m){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 1; i <= k; ++i) {
            pq.push(1ll * i * m + s);
        }
        ll cnt = 0, totalTime = 0, digAvailable = 0;
        while(cnt < 1e4){
            ll curr = pq.top();
            pq.pop();
            cnt += c;
            totalTime = max(digAvailable, curr) + w + s;
            digAvailable = max(digAvailable, curr) + w;
            pq.push(digAvailable + 2 * s);
        }
        cout << totalTime << nl;
    }
}

