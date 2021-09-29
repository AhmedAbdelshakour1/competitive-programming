// https://cses.fi/problemset/task/1161/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
typedef long long ll;
 
int main(){
    IO();
    ll n, x; cin >> x >> n;
    priority_queue<ll, vector<ll>, greater<int>> p;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        p.push(a);
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        int cur1 = p.top();
        p.pop();
        int cur2 = p.top();
        p.pop();
        ans += cur1 + cur2;
        p.push(cur1 + cur2);
    }
    cout << ans;
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
