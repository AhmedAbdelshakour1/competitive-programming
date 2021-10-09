// http://www.usaco.org/index.php?page=viewproblem2&cpid=760

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
int order[100], newOrder[100], shuf[100];
int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%d", &n);
    rep(i, 0, n)scanf("%d", &shuf[i]);
    rep(i, 0, n)scanf("%d", &order[i]);
    rep(j, 0, 3){
        rep(i, 0, n)
        newOrder[i] = order[shuf[i] - 1];
        rep(i, 0, n) order[i] = newOrder[i];
    }
    rep(i, 0, n) cout << newOrder[i] << endl;
}
