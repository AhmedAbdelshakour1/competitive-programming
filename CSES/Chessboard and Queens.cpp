// https://cses.fi/problemset/task/1624/

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
#define forn(i, a, n) for(int i = a; i <= ; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int  ans = 0;
int visted[8], digR[17], digL[17];
char grid[8][8];
void search(int y){
    if(y == 8){
        ans++;
        return;
    }
    for(int x = 0; x < 8; x++){
        if(grid[y][x] == '.' && !visted[x] && !digR[x + y] && !digL[x - y + 7]){
            visted[x] = digL[x - y + 7] = digR[x + y] = 1;
            search(y + 1);
            visted[x] = digL[x - y + 7] = digR[x + y] = 0;
        }
    }
}
 
int main() {
    IO();
 
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }
    search(0);
    cout << ans << newline;
}
