// http://www.usaco.org/index.php?page=viewproblem2&cpid=360

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
int n, ans, X[15], Y[15], pairs[15], nxt[15];
bool check() {
    for(int i = 1; i <= n; i ++) {
        int cur = pairs[i];
        for(int j = 0; j <= n; j++) {
            cur = nxt[pairs[cur]];
        }
        if(cur) return true;
    }
    return false;
}
 
void solve() {
    int i = 1;
    for(; i <= n; i++) {
        if(pairs[i] == 0) {
            pairs[i] = -1;
            break;
        }
    }
    if(i > n) {
        ans += check();
        return;
    }
    for(int j = 1; j <= n; j++) {
        if(pairs[j] == 0) {
            pairs[j] = i;
            pairs[i] = j;
            solve();
            pairs[i] = pairs[j] = 0;
        }
    }
}
int main() {
    IO();
    freopen ("wormhole.in","r",stdin);
    freopen ("wormhole.out","w",stdout);
 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(Y[i] == Y[j] && X[i] > X[j])
            nxt[i] = j;
        }
    }
   solve();
    cout << ans << newline;
}
