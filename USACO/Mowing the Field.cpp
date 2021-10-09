// http://www.usaco.org/index.php?page=viewproblem2&cpid=593

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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N, steps ,x , y, Px = 1000, Py = 1000, countTime = 0,  MaxSol = 1001;
    char c;
    vector<vector<int>> v(2002, vector<int>(2002, -1));
    v[Px][Py] = 0;
    scanf("%d", &N);
    rep(i, 0, N){
       cin >> c >> steps;
        x = 0, y = 0;
        if(c == 'N') y = 1;
        else if(c == 'S') y = - 1;
        else if(c == 'E') x = 1;
        else if(c == 'W') x = - 1;
        rep(j, 0, steps){
            Px += x;
            Py += y;
            countTime++;
            if(v[Px][Py] >= 0 && countTime - v[Px][Py] < MaxSol)
                MaxSol = countTime - v[Px][Py];
             v[Px][Py] = countTime;
        }
    }
    if(MaxSol == 1001) cout << -1 << endl ;
    else cout << MaxSol << endl;
}
