// https://vjudge.net/problem/UVA-11953

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
char grid[101][101];
bool vis[101][101];
int n;
int d4x[4] = {0, 0, -1, 1};
int d4y[4] = {1, -1, 0, 0};
bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int moveX = i + d4x[k];
        int moveY = j + d4y[k];
        if(valid(moveX, moveY) && !vis[moveX][moveY] && (grid[moveX][moveY] == 'x' || grid[moveX][moveY] == '@'))
            dfs(moveX, moveY);
    }
}
int main(){
    int t; scanf("%d", &t);
    for (int test = 1; test <= t; ++test) {
        memset(vis, false, sizeof(vis));
        memset(grid, 0, sizeof(grid));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf(" %c", &grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j] == 'x' && !vis[i][j]) {
                    ans++;
                    dfs(i, j );
                }
            }
        }
        printf("Case %d: %d\n", test, ans);
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
