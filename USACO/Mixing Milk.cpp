// http://www.usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int c[3], m[3];
    rep(i, 0, 3) {
        scanf("%d", &c[i]);
        scanf("%d", &m[i]);
    }
    rep(i, 0, 100){
        int cur = i % 3;
        int next = (i + 1) % 3;
        if(m[cur] + m[next] <= c[next]){
            m[next] += m[cur];
            m[cur] = 0;
        }else {
            m[cur] -= c[next] - m[next];
            m[next] = c[next];
        }
    }
    rep(i, 0, 3) cout << m[i] << endl;
}
