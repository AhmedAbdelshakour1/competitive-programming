// http://www.usaco.org/index.php?page=viewproblem2&cpid=616

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
 
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int N;
    scanf("%d", &N);
    int a[N];
    int totalCow = 0;
    rep(i, 0, N){
        scanf("%d", &a[i]);
        totalCow += a[i];
    }
    int ans = INT_MAX;
    rep(start, 0, N){
        int partSol = 0, curTotal = totalCow;
        rep(i, 0, N){
            curTotal -= a[(start + i) % N];
            partSol += curTotal;
        }
        ans = min(ans, partSol);
    }
    printf("%d", ans);
}
