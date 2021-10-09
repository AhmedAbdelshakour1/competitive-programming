// http://www.usaco.org/index.php?page=viewproblem2&cpid=617

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
pii points[101];
int n, b, ans = INT_MAX;
void maxInGroup(int x, int y){
    int Regions[4] = {0};
    for(int i = 0; i < n; i++){
        if(points[i].fir < x && points[i].sec < y)
            Regions[0]++;
        else if(points[i].fir > x && points[i].sec < y)
            Regions[1]++;
        else if(points[i].fir < x && points[i].sec > y)
            Regions[2]++;
        else if(points[i].fir > x && points[i].sec > y)
            Regions[3]++;
    }
    ans = min(ans, max({Regions[0], Regions[1], Regions[2], Regions[3]}));
}
int main() {
    freopen ("balancing.in","r",stdin);
    freopen ("balancing.out","w",stdout);
 
    cin >>  n >> b;
    for(int i = 0; i < n; i++)
        cin >> points[i].fir >> points[i].sec;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            maxInGroup(points[i].fir + 1, points[j].sec + 1);
        }
    }
    cout << ans << newline;
}
