// http://www.usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main() {
    int m, n, k;
    //freopen("main.in", "r", stdin);
    //freopen("main.out", "w", stdout);
    scanf("%d %d %d", &m, &n, &k);
 
    char a[m * k][n * k];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
 
    for (int i = 0; i < m; i++) {
        for (int x = 0; x < k; x++) {
            for (int j = 0; j < n; j++) {
                for (int y = 0; y < k; y++)
                    cout << a[i][j];
            }
            cout << endl;
 
        }
    }
}
