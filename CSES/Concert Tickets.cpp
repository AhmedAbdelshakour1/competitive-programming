// https://cses.fi/problemset/task/1091/

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
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> t;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        t.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        auto it = t.lower_bound(x);
        if(it != t.end()){
            cout << *it << "\n";
            t.erase(it);
        }else cout << -1 << "\n";
    }
}
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
     No idea is a BAD idea!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
 */
