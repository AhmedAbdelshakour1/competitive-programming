// http://www.usaco.org/index.php?page=viewproblem2&cpid=735

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define F first
#define S second
int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    scanf("%d %d", &x, &y);
    int dir = 1, sol = 0, pos = x, newPos = x;
    ll multiply = 1;
    while (true){
        if((dir == 1 && x + multiply >= y && y >= x) || (dir == -1 && x - multiply <= y && y <= x)){
            sol += abs(y - pos);
            cout << sol << endl;
            break;
        }else {
            if(dir == -1)
                newPos = x - multiply;
            else newPos = x + multiply;
            sol += abs(pos - newPos);
            pos = newPos;
            multiply *= 2;
            dir *= -1;
        }
    }
}
