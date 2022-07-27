// https://vjudge.net/problem/UVA-11494#author=0

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

string toString(ll number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

bool powerOfTwo(ll n) {
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
        int x1, y1, x2, y2;
        while(cin >> x1 >> y1 >> x2 >> y2 && x1 + y1 + x2 + y2 > 0){
            if(x1 == x2 && y1 == y2){
                cout << "0\n";
            }else if(x1 == x2 || y1 == y2){
                cout << "1\n";
            }else if(x1 + y1 == x2 + y2){
                cout << "1\n";
            }else if(x1 - y1 == x2 - y2){
                cout << "1\n";
            }else cout << "2\n";
        }
    }
