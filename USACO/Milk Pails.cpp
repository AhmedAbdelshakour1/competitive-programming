// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
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
 
//void IO(){
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//}
 
 
int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m,  sol = 0, sum = 0;
    scanf("%d %d %d", &x, &y, &m);
 
    if(m % x == 0 || m % y == 0){
        printf("%d", m);
        return 0;
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            sum = (x * j) + (y * i);
            if(sum <= m) sol = max(sol, sum);
            else break;
        }
    }
    printf("%d",sol);
}
