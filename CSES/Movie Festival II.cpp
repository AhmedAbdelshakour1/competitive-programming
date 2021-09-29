// https://cses.fi/problemset/task/1632/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
typedef pair<long long, long long> pii;
 
int main() {
    int n, k;
    cin >> n >> k;
    pair<long long, long long> p[n];
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n, [](pii &a, pii &b) {
        return a.second < b.second;
    });
    multiset<long long, greater<int>> m;
    while (k--) {
        m.insert(-1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = m.lower_bound(p[i].first);
        if (it != m.end()) {
            m.erase(it);
            m.insert(p[i].second);
            ans++;
        }
    }
    cout << ans << '\n';
 
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
