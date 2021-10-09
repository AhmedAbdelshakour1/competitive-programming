// http://www.usaco.org/index.php?page=viewproblem2&cpid=919

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
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
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int v[1001][1001];
int main() {
    IO();
    freopen ("paintbarn.in" , "r", stdin);
    freopen ("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; j++){
            v[j][y1] += 1;
            v[j][y2] -= 1;
        }
    }
    for(int i = 0; i < 1001; i++)
        for(int j = 1; j < 1001; j++)
            v[i][j] += v[i][j-1];
 
    int ans = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (v[i][j] == k) ans++;
        }
    }
    cout << ans;
}
