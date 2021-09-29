// https://cses.fi/problemset/task/1073/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main() {
    IO();
    int n; cin >> n;
    multiset<long long> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.end()) s.insert(x);
        else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
}
 
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
 */
