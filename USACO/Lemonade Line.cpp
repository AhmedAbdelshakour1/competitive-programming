// http://www.usaco.org/index.php?page=viewproblem2&cpid=835

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
typedef long long ll;
 
int main() {
    IO();
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = n - 1; i >= 0; i--)
        if(v[i] >= ans) ans++;
        cout << ans << '\n';
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
