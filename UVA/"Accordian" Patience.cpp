// https://vjudge.net/problem/UVA-127#author=0

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nl '\n';
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


ll binPow(ll a, ll p) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.........................................(^_^)............................................//
int main() {
    while (1) {
        vector <stack<string>> v;
        for (int i = 1; i <= 52; ++i) {
            string s;
            cin >> s;
            if (s == "#") return 0;
            stack <string> st;
            st.push(s);
            v.push_back(st);
        }
        for (int i = 1; i < len(v); ++i) {
            if (i - 3 >= 0 && (v[i - 3].top()[0] == v[i].top()[0] || v[i - 3].top()[1] == v[i].top()[1])) {
                v[i - 3].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) v.erase(v.begin() + i, v.begin() + i + 1);
                i -= 4;
            } else if (i - 1 >= 0 &&
                       (v[i - 1].top()[0] == v[i].top()[0] || v[i - 1].top()[1] == v[i].top()[1])) {
                v[i - 1].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) v.erase(v.begin() + i, v.begin() + i + 1);
                i -= 2;
            }
        }
        if(len(v) == 1)
            cout << len(v) << " pile remaining:";
        else cout << len(v) << " piles remaining:";
        for (int i = 0; i < len(v); ++i) {
            cout << " " << len(v[i]);
        }
        cout << nl;
    }
}

