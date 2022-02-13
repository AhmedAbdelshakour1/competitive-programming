// https://vjudge.net/problem/UVA-10344

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
int v[5], vis[5];
int valid;
void backtracking(int sz, int currTot, int isFirst){
    if(sz == 5){
        valid |= (currTot == 23);
        return;
    }
    if(valid) return;
    for (int i = 0; i < 5; ++i) {
        if(vis[i]) continue;
        vis[i] = 1;
        if(isFirst) backtracking(sz + 1, v[i], 0);
        else {
            backtracking(sz + 1, currTot + v[i], 0);
            backtracking(sz + 1, currTot - v[i], 0);
            backtracking(sz + 1, currTot * v[i], 0);
        }
        vis[i] = 0;
    }
}
int main(){
    while(1) {
        valid = 0;
        for (int &i: v) {
            scanf("%d", &i);
        }
        int sum = accumulate(v, v + 5, 0);
        if(!sum) return 0;
        backtracking(0, 0, 1);
        if(valid) puts("Possible");
        else puts("Impossible");
    }
}
