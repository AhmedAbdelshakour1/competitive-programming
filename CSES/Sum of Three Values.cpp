// https://cses.fi/problemset/task/1641/

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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v[i].first = num;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for (int mid = 0; mid < n; mid++) {
        int i = 0, j = n - 1;
        while (i != j) {
            int sum = v[i].first + v[j].first + v[mid].first;
            if(sum == x && i != mid && i != j && j != mid) {
                cout << v[i].second << " " << v[j].second << " " << v[mid].second;
                return 0;
            }else if(sum > x) j--;
            else  i++;
        }
    }
    cout << "IMPOSSIBLE";
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
