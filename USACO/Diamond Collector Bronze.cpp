// http://www.usaco.org/index.php?page=viewproblem2&cpid=639

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
 
//void IO(){
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//}
 
 
int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    rep(i, 0, n) scanf("%d", &v[i]);
    sort(all(v));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int diff = 1;
        for (int j = i + 1; j < n; j++) {
            if (v[j] - v[i] <= k)
                diff++;
        }
            ans = max(ans, diff);
    }
    printf("%d", ans);
}
