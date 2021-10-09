// http://www.usaco.org/index.php?page=viewproblem2&cpid=807

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b, x, y;
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    scanf("%d %d %d %d", &a, &b, &x, &y);
    int t1 = abs(a - x) + abs(b - y);
    int t2 = abs(a - y) + abs(b - x);
    cout << min(min(t1, t2), abs(a - b));
}
