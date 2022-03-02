// https://vjudge.net/problem/UVA-10036

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
int n, k, flag;
int v[10001], memo[10001][101];
int fix(int m){
    return (m % k + k) % k;
}
int solve(int indx, int mod){
    int &ret = memo[indx][mod];
    if(~ret) return ret;
    if(indx == n){
         ret = mod == 0;
         if(ret) flag = 1;
        return ret;
    }
    if(solve(indx + 1, fix(mod + v[indx])) || solve(indx + 1, fix(mod - v[indx])))
        return ret = 1;
    return ret = 0;
}
int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
        memset(memo, -1, sizeof memo);
        flag = 0;
        solve(1, fix(v[0]));
        if(flag){
            puts("Divisible");
        }else puts("Not divisible");

    }
}
