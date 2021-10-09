// http://www.usaco.org/index.php?page=viewproblem2&cpid=759

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
struct rect{
    int x1, y1, x2, y2;
};
///this intersection not visible area.
int intersection(rect A, rect B){
    int overLapX = max(0, min(A.x2, B.x2) - max(A.x1, B.x1));
    int overLapY = max(0, min(A.y2, B.y2) - max(A.y1, B.y1));
    return overLapX * overLapY;
}
int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
 rect a, b, t;
 scanf("%d %d %d %d", &a.x1, &a.y1, &a.x2, &a.y2);
 scanf("%d %d %d %d", &b.x1, &b.y1, &b.x2, &b.y2);
 scanf("%d %d %d %d", &t.x1, &t.y1, &t.x2, &t.y2);
 
 /// rect's area a
 int areaA = (a.y2 - a.y1) * (a.x2 - a.x1);
 /// rect's area b
 int areaB = (b.y2 - b.y1) * (b.x2 - b.x1);
 
 cout << areaA + areaB - (intersection(a, t) + intersection(b, t));
}
