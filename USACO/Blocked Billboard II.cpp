// http://www.usaco.org/index.php?page=viewproblem2&cpid=783

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int a, b, c, d, x1, y1, x2, y2;
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &x1, &y1, &x2, &y2);
    int x, y;
 
    if ((a >= x1 && c <= x2) && (b >= y1 && d <= y2))
        cout << 0;
    else {
        if (((x1 <= c && x1 > a) && (y1 <= b && y2 >= d)) && (x2 >= c)) {
            x = abs(c - a) - abs(x1 - c);
            y = abs(d - b);
            cout << x * y;
        } else if (((x2 >= a && x2 < c) && (y1 <= b && y2 >= d)) && (x1 <= a)) {
            x = abs(c - a) - abs(a - x2);
            y = abs(d - b);
            cout << x * y;
        } else if (((y2 >= d) && (y1 <= d && y1 > b)) && (x1 <= a && x2 >= c)) {
            x = abs(c - a);
            y = abs(d - b) - abs(d - y1);
            cout << x * y;
        } else if (((y1 <= b) && (y2 >= b && y2 < d)) && (x1 <= a && x2 >= c)) {
            x = abs(c - a);
            y = abs(d - b) - abs(y2 - b);
            cout << x * y;
        } else cout << abs(d - b) * abs(c - a);
    }
}
