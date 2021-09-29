// https://cses.fi/problemset/task/1625/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef long long ll;
 
string s;
int vis [7][7];
int ans = 0;
bool ok(int x, int y){
    return (x >= 0 && y >= 0 && x < 7 && y < 7);
 
}
void path(int x, int y, int idx) {
 
    if (x == 0 && y == 6) {
        if (idx == 48) ans++;
        return;
    }
 
    if (ok(x - 1, y) && vis[x - 1][y])
    if (ok(x + 1, y) && vis[x + 1][y])
        if (ok(x, y - 1) && !vis[x][y - 1])
            if (ok(x, y + 1) && !vis[x][y + 1])
                return;
 
    if (ok(x, y - 1) && vis[x][y - 1])
        if (ok(x, y + 1) && vis[x][y + 1])
            if (ok(x - 1, y) && !vis[x - 1][y])
                if (ok(x + 1, y) && !vis[x + 1][y])
                    return;
 
    if (x == 6 || x == 0) {
        if (ok(x, y - 1) && !vis[x][y - 1])
            if (ok(x, y + 1) && !vis[x][y + 1])
                return;
    }
    if (y == 6 || y == 0)
        if (ok(x - 1, y) && !vis[x - 1][y])
            if (ok(x + 1, y) && !vis[x + 1][y])
                return;
 
        vis[x][y] = 1;
 
        if (s[idx] == '?' || s[idx] == 'R') {
            if (ok(x + 1, y) && vis[x + 1][y] == 0) path(x + 1, y, idx + 1);
        }
        if (s[idx] == '?' || s[idx] == 'L') {
            if (ok(x - 1, y) && vis[x - 1][y] == 0) path(x - 1, y, idx + 1);
        }
        if (s[idx] == '?' || s[idx] == 'D') {
            if (ok(x, y + 1) && vis[x][y + 1] == 0) path(x, y + 1, idx + 1);
        }
        if (s[idx] == '?' || s[idx] == 'U') {
            if (ok(x, y - 1) && vis[x][y - 1] == 0) path(x, y - 1, idx + 1);
        }
 
        vis[x][y] = 0;
}
int main() {
    IO();
    cin >> s;
    path(0, 0, 0);
    cout << ans;
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
