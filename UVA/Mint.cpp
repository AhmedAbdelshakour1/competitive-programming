// https://vjudge.net/problem/UVA-10717

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

//.....................................................................................//
int lcm(int a, int b, int c, int d){
    int x = a * b / __gcd(a, b);
    int y = x * c / __gcd(x, c);
    return y * d / __gcd(y, d);
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && n && m) {
        vector<int> v(n);
        for (int &i: v) scanf("%d", &i);
        for (int z = 0; z < m; z++) {
            int a, mn = INT_MAX, mx = 0;
            scanf("%d", &a);
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for (int l = k + 1; l < n; ++l) {
                            int val = lcm(v[i], v[j], v[k], v[l]);
                            int x = a / val * val;
                            if(a %  lcm(v[i], v[j], v[k], v[l]) == 0) mn = min(mn, a);
                            else mn = min(mn , x + val);
                            mx = max(mx, x);
                        }
                    }
                }
            }
            printf("%d %d\n", mx, mn);
        }
    }
}
