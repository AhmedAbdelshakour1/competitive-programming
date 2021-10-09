// http://www.usaco.org/index.php?page=viewproblem2&cpid=987

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define F first
#define S second
int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k;
    string currW;
    scanf("%d %d", &n, &k);
    int currL = 0;
    rep(i, 0, n){
        cin >> currW;
        if(currL + currW.length() > k){
            cout << endl << currW;
            currL = currW.length();
        }else {
            if (currL == 0) cout << currW;
            else cout << " " << currW;
                currL += currW.length();
 
        }
    }
 
}
