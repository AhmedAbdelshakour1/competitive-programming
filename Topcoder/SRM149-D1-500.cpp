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
class MessageMess {
public:
    string m;
    vector<string> d;
    const static int N = 60;
    string memo[N][N];

    string solve(int x, int y) {
        string &ret = memo[x][y];
        if (ret != "") return ret;
        ret = "IMPOSSIBLE!";
        for (int i = 0; i < len(d); ++i) {
            if (d[i] == m.substr(x, y - x)) {
                ret = d[i];
                break;
            }
        }
        for (int i = x + 1; i < y; ++i) {
            string l = solve(x, i);
            string r = solve(i, y);
            if (l != "IMPOSSIBLE!" && r != "IMPOSSIBLE!") {
                if (ret != "IMPOSSIBLE!" && ret != l + " " + r) return "AMBIGUOUS!";
                else ret = l + " " + r;
            }
        }
        return ret;
    }
    string restore(vector <string> dictionary, string message){
        m = message;
        d = dictionary;
        return solve(0, len(m));
    }
};
//int main() {
//
//    int n; cin >> n;
//    cin >> m;
//    for (int i = 0; i < n; ++i) {
//        string s; cin >> s;
//        d.push_back(s);
//    }
//    cout << solve(0, len(m));
//}
