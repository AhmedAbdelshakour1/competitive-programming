// http://www.usaco.org/index.php?page=viewproblem2&cpid=571

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    IO();
    freopen ("highcard.in", "r", stdin);
    freopen ("highcard.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    set<int> bess, ele;
    for(int i = 1; i <= 2 * n; i++) bess.insert(i);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ele.insert(x);
        bess.erase(x);
    }
    for(auto cur : ele) {
        auto it = bess.upper_bound(cur);
        if (it == bess.end()) break;
            ans++;
            bess.erase(it);
 
    }
    cout << ans;
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
