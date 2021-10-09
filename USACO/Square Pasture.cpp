// http://www.usaco.org/index.php?page=viewproblem2&cpid=663

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main() {
    int x1, y1, x2, y2, w1, z1, w2, z2;
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &w1, &z1, &w2, &z2);
    int mn1 = min(x1, w1);
    int mn2 = min(y1, z1);
    int mx1 = max(x2, w2);
    int mx2 = max(y2, z2);
    int area = max(abs(mn1 - mx1), abs(mn2 - mx2));
    printf("%d", area * area);
}
