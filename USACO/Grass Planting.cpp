// http://www.usaco.org/index.php?page=viewproblem2&cpid=894

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
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        v[a - 1]++;
        v[b - 1]++;
    }
    int ans = 0;
    for(int i = 0; i < v.size(); i++) ans = max(ans, v[i]);
    cout << ans + 1;
}
