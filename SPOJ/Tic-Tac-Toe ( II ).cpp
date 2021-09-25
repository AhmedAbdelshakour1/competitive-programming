// https://www.spoj.com/problems/TOE2/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
#define INF 0x3f3f3f3f
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4]{-1, 1, 0, 0};
int dy4[4]{-0, 0, -1, 1};
 
ll pow(int b, int p) {   // O(log(p) base 2)
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
bool is_win(string &curr) {
    bool flag = true;
    for (int i = 0; i < 9; ++i) {
        if(curr[i] == '.') flag = false;
    }
    bool row = (curr[0] != '.' && curr[0] == curr[1] && curr[1] == curr[2]) ||
               (curr[3] != '.' && curr[3] == curr[4] && curr[4] == curr[5]) ||
               (curr[6] != '.' && curr[6] == curr[7] && curr[7] == curr[8]);
 
    bool col = (curr[0] != '.' && curr[0] == curr[3] && curr[3] == curr[6]) ||
               (curr[1] != '.' && curr[1] == curr[4] && curr[4] == curr[7]) ||
               (curr[2] != '.' && curr[2] == curr[5] && curr[5] == curr[8]);
 
    bool dia = (curr[0] != '.' && curr[0] == curr[4] && curr[4] == curr[8]) ||
               (curr[2] != '.' && curr[2] == curr[4] && curr[4] == curr[6]);
    return row || col || dia || flag;
}
 
int main() {
    IO();
    string s;
    while (cin >> s && s != "end") {
        string st = ".........";
        string ans = "invalid";
        queue<pair<string, int>> q;
        q.push({st, 1});
        while (q.size()) {
            string curr = q.front().first;
            int currPlayer = q.front().second;
            q.pop();
            if (curr == s && is_win(curr)) {
                ans = "valid";
                break;
            }
            if (is_win(curr)) continue;
            for (int i = 0; i < 9; i++) {
                if (curr[i] == '.') {
                    curr[i] = (currPlayer == 1 ? 'X' : 'O');
                    if (curr[i] == s[i]) q.push({curr, 1 ^ currPlayer});
                    curr[i] = '.';
                }
            }
        }
        cout << ans << endl;
    }
}
 
/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/
