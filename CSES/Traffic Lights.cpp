// https://cses.fi/problemset/task/1163/

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
    int x, n;
    cin >> x >> n;
    set<int> tlights;
    multiset<int> dis;
    tlights.insert(0);
    tlights.insert(x);
    dis.insert(x);
    while(n--){
        int pos;
        cin >> pos;
        auto it1 = tlights.upper_bound(pos);
        auto it2 = it1;
        it2--;
        dis.erase(dis.find(*it1 - *it2));
        dis.insert(*it1 - pos);
        dis.insert(pos - *it2);
        tlights.insert(pos);
        cout << *--dis.end() << " ";
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
