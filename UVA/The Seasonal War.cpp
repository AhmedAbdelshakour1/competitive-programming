// https://vjudge.net/problem/UVA-352

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
char grid[30][30];
bool vis[30][30];
int n;
bool valid_move(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
void dfs(int i, int j){
    if(vis[i][j]) return;
    vis[i][j] = true;
    for(int dir = 0; dir < 8; dir++){
        int xc = dx[dir] + i;
        int yc = dy[dir] + j;
        if(valid_move(xc, yc) && !vis[xc][yc] && grid[xc][yc] == '1')
            dfs(xc, yc);
    }
}
int main() {
    int test = 0;
    while(scanf("%d", &n) != EOF) {
        memset(vis, false, sizeof(vis));
        test++;
        int ans = 0;
        for (int i = 0; i < n; i++)
                scanf("%s", grid[i]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", test, ans);
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
