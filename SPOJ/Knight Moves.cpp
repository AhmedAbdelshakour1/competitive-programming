// https://vjudge.net/problem/UVA-439

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
int move_x[] = {1, 1, 2, 2, -1, -1, -2, -2};
int move_y[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool vis[10][10];
char s1[5], s2[5];
 
int main() {
    while (scanf("%s%s", s1, s2) != EOF) {
        memset(vis, false, sizeof vis);
        int row_src = s1[1] - '1';
        int row_des = s2[1] - '1';
        int col_src = s1[0] - 'a';
        int col_des = s2[0] - 'a';
        queue<pair<pair<int, int>, int>> q;
        q.push({{row_src, col_src}, 0});
        vis[row_src][col_src] = true;
        int ans = 1e3;
        while (q.size()) {
            auto curr = q.front();
            q.pop();
            int curr_row = curr.first.first;
            int curr_col = curr.first.second;
            int w = curr.second;
            if (curr_row == row_des && curr_col == col_des) ans = min(ans, w);
 
            for (int i = 0; i < 8; i++) {
                int dir_x = curr_row + move_x[i];
                int dir_y = curr_col + move_y[i];
                if (!vis[dir_x][dir_y] && dir_x >= 0 && dir_x < 8 && dir_y >= 0 && dir_y < 8) {
                    vis[dir_x][dir_y] = true;
                    q.push({{dir_x, dir_y}, w + 1});
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, ans);
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
