// http://www.usaco.org/index.php?page=viewproblem2&cpid=1011

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
struct point{
    int x, y;
    point(int a, int b){
        x = a;
        y = b;
    }
};
//if a.x == b.x this mean the side parallel to y-axis and vice versa...
bool check(point a, point b, point c){
    return((b.x == c.x && a.y == b.y) || (a.x == b.x && a.y == c.y) ||
            (c.x == a.x && c.y == b.y) || (b.x == a.x && b.y == c.y) ||
            (a.x == c.x && a.y == b.y) || (a.y == c.y && b.x == c.x));
}
int area(point a, point b, point c){
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
 
int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    IO();
    int n;
    cin >> n;
    vector<point> v;
    forl(i, 0, n) {
        int x, y;
        cin >> x >> y;
        v.pb(point(x, y));
    }
    int ans = -1;
    forl(i, 0, n) {
        forl(j, i + 1, n) {
            forl(k, j + 1, n) {
                if (check(v[i], v[j], v[k])) {
                    ans = max(ans, area(v[i], v[j], v[k]));
                }
            }
        }
    }
    cout << ans;
}
