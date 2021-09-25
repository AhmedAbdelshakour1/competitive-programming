// https://vjudge.net/problem/UVA-10452

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
vector<string> path;
char grid[9][9];
string p[] = {"forth", "left", "right"};
string safe = "IEHOVA#";
int x[3] = {-1, 0, 0};
int y[3] = {0, -1, 1};
int n, m;
bool valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
 
 
void dfs(int i, int j, int curr) {
    if(curr >= safe.size()) return;
    for (int dir = 0; dir < 3; dir++) {
        int xc = x[dir] + i;
        int yc = y[dir] + j;
        if (valid(xc, yc) && grid[xc][yc] == safe[curr]) {
            path.push_back(p[dir]);
            dfs(xc, yc, curr + 1);
        }
    }
}
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(grid, 0, sizeof(grid));
        path.clear();
        scanf("%d %d", &m, &n);
 
        for (int j = 0; j < m; j++)
            scanf("%s", grid[j]);
        int a, b;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@')
                    a = i, b = j;
            }
        }
        dfs(a, b, 0);
        printf("%s", path[0].c_str());
        for (int i = 1; i < path.size(); ++i) {
            printf(" %s", path[i].c_str());
        }
        puts("");
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
