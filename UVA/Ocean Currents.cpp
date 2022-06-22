// https://vjudge.net/problem/UVA-11573#author=0

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
const int N = 1e3 + 1;
int matrix[N][N], cost[N][N];
int n, m, q;
pair<int, int> src, dist;

bool valid(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m;
}

bool direction(int x, int a, int b) {
    if (x == 0 && a == -1 && b == 0) return true;
    if (x == 1 && a == -1 && b == 1) return true;
    if (x == 2 && a == 0 && b == 1) return true;
    if (x == 3 && a == 1 && b == 1) return true;
    if (x == 4 && a == 1 && b == 0) return true;
    if (x == 5 && a == 1 && b == -1) return true;
    if (x == 6 && a == 0 && b == -1) return true;
    if (x == 7 && a == -1 && b == -1) return true;
    return false;
}

int bfs() {
    deque<pair<int, int>> qq;
    qq.push_back(src);
    cost[src.first][src.second] = 0;
    while (len(qq)) {
        auto curr = qq.front();
        qq.pop_front();
        for (int i = 0; i < 8; ++i) {
            int moveX = curr.first + dx[i];
            int moveY = curr.second + dy[i];
            if (valid(moveX, moveY)) {
                if(direction(matrix[curr.first][curr.second], dx[i], dy[i]) && cost[curr.first][curr.second] < cost[moveX][moveY]){
                    qq.push_front({moveX, moveY});
                    cost[moveX][moveY] = cost[curr.first][curr.second];
                }else if(!direction(matrix[curr.first][curr.second], dx[i], dy[i]) && cost[curr.first][curr.second] + 1 < cost[moveX][moveY]){
                    qq.push_back({moveX, moveY});
                    cost[moveX][moveY] = cost[curr.first][curr.second] + 1;
                }
            }
        }
    }
    return cost[dist.first][dist.second];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; cin >> x;
            matrix[i][j] = x - '0';
        }
    }
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        memset(cost, MOD, sizeof cost);
        src = {a - 1, b - 1};
        dist = {c - 1, d - 1};
        if(src == dist){
            cout << "0\n";
            continue;
        }
        cout << bfs() << nl;
    }
}

