// https://vjudge.net/problem/UVA-378

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
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
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

int main() {
    int t;
    scanf("%d", &t);
    puts("INTERSECTING LINES OUTPUT");
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        double b1 = x2 - x1;
        double c2 = x3 * y4 - x4 * y3;
        double b2 = x4 - x3;
        double c1 = x1 * y2 - x2 * y1;
        double a1 = y1 - y2;
        double a2 = y3 - y4;

        double a = x2 - x1;
        double c = x4 - x3;
        double b = y2 - y1;
        double d = y4 - y3;
        double cp = a * d - c * b;
        if(cp != 0){
            printf("POINT %.2f %.2f\n", (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1),
                   (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1));
        }else if(a1 * x3 + a * y3 + c1 == 0) puts("LINE");
        else  puts("NONE");
    }
    puts("END OF OUTPUT");
}
