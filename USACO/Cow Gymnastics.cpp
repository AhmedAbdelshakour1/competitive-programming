// http://www.usaco.org/index.php?page=viewproblem2&cpid=963

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
int n, k;
bool better(int a, int b, vector<vector<int>> & v){
    int aj, bj,  counter = 0;
    rep(i, 0, k){
        rep(j, 0, n){
            if(v[i][j] == a) aj = j;
            else if(v[i][j] == b)  bj = j;
        }
        if(aj < bj) counter++;
    }
    return counter == k;
}
 
int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
 
    scanf("%d %d", &k, &n);
    vector<vector<int>> v(k, vector<int>(n));
    rep(i, 0, k)
        rep(j, 0, n) cin >> v[i][j];
    int sol = 0;
    rep(d, 0, n) {
        rep(q, d + 1, n) {
            if (better(v[0][d], v[0][q], v)) sol++;
        }
    }
    printf("%d", sol);
}
