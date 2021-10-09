// http://www.usaco.org/index.php?page=viewproblem2&cpid=595

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
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
 
int main() {
    IO();
    freopen ("div7.in", "r", stdin);
    freopen ("div7.out", "w", stdout);
    int n, ans = 0; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) v[i] = (v[i] + v[i - 1]) % 7;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++) mp[v[i]].pb(i);
    for(auto &x : mp){
        if(x.sec.size() > 1){
            ans = max(ans, x.sec[x.sec.size() - 1] - x.sec[0]);
        }
    }
    cout << ans << newline;
}
