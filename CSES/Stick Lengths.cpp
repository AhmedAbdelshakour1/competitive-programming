// https://cses.fi/problemset/task/1074/

/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
#include <bits/stdc++.h>
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    long long n, ans = 0, x;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    x = n / 2;
    for(int i = 0; i < n; i++)
        ans += abs(v[i] - v[x]);
    cout << ans;
}
