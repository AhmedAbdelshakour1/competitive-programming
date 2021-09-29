// https://cses.fi/problemset/task/1630/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    long long n; cin >> n;
    vector<pair<long long, long long>> p(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p.begin(), p.end());
    long long ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum+= p[i].first;
        ans += p[i].second - sum;
    }
    cout << ans;
}
 
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
