// http://www.usaco.org/index.php?page=viewproblem2&cpid=891

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define F first
#define S second
int A[100], B[100], G[100];
int probWin(int p, int n){
    int currP = p;
    int win = 0;
    rep(i, 0, n){
        if(A[i] == currP)
            currP = B[i];
        else if(B[i] == currP)
            currP = A[i];
        if(G[i] == currP) win++;
    }
    return  win;
}
int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    scanf("%d", &n);
    rep(i, 0, n){
        scanf("%d %d %d", &A[i], &B[i], &G[i]);
    }
    int ans = INT_MIN;
    rep(i, 1, 4){
        ans = max(ans, probWin(i, n));
    }
    cout << ans;
   }
