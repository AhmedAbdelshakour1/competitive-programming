// http://www.usaco.org/index.php?page=viewproblem2&cpid=784

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
 
int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    IO();
    int n, x, y, ans = -1e9;
    cin >> n;
    vector<pair<int, int>> v;
    forl(i, 0, n){
        cin >> x >> y;
        v.pb({x, y});
    }
    forl(i, 0, n){
        vector<int> time(1001, 0);
        forl(j, 0, n){
            if(i != j){
                forl(k, v[j].fir, v[j].sec) time[k] = 1;
            }
        }
      int timeAns = 0;
        forl(t, 0, 1001) timeAns += time[t];
        ans = max(ans, timeAns);
    }
    cout << ans;
}
