// https://cses.fi/problemset/task/1629/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    long long n, ans = 1; cin >> n;
    vector<pair<long long, long long>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    long long prev = v[0].first;
    for(int i = 1; i < n; i++){
        if(v[i].second >= prev) {
            ans++;
            prev = v[i].first;
        }
    }
    cout << ans << '\n';
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
