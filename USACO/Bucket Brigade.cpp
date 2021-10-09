// http://www.usaco.org/index.php?page=viewproblem2&cpid=939

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define F first
#define S second
int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int Bi, Bj, Li, Lj, Ri, Rj;
    char ar[10][10];
    rep(i, 0, 10) {
        rep(j, 0, 10) cin >> ar[i][j];
    }
    rep(i, 0, 10){
        rep(j, 0, 10){
            if(ar[i][j] == 'B'){
                Bi = i;
                Bj = j;
            }
            if(ar[i][j] == 'L'){
                Li = i;
                Lj = j;
            }
            if(ar[i][j] == 'R'){
                Ri = i;
                Rj = j;
            }
        }
    }
    int disBR = abs(Bi - Ri) + abs(Bj - Rj);
    int disBL = abs(Bi - Li) + abs(Bj - Lj);
    int disRL = abs(Li - Ri) + abs(Lj - Rj);
    //if there is rock  between B and L
    if(((Bi == Li) || (Bj == Lj)) && (disBL == disBR + disRL))
        cout << disBL + 1;
    //if there is rock(not between B and L) you can solve by Manhattan distance
    else cout << disBL - 1;
}
