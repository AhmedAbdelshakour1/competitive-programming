// https://atcoder.jp/contests/abc070/tasks/abc070_b?lang=en

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

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(c >= a && c <= b){
        if(d <= b) printf("%d", d - c);
        else  printf("%d", b - c);
    }else if(c < a){
        if(d <= b && d >= a)  printf("%d", d - a);
        else if(d > b) printf("%d", b - a);
        else puts("0");
    }else puts("0");
}
