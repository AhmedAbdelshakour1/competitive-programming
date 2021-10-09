// http://www.usaco.org/index.php?page=viewproblem2&cpid=762

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    double ans = 0.0;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) v[i] += v[i - 1];
    for (int i = 1; i < n - 1; i++)
        ans = max(ans, 1.0 * (v[n] - v[i]) / (1.0 * (n - i)));
 
    for (int i = 1; i < n - 1; i++) {
        if ((1.0 * (v[n] - v[i])) / (1.0 * (n - i)) == ans)
            cout << i << '\n';
    }
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
