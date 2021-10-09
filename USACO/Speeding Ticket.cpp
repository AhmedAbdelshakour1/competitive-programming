// http://www.usaco.org/index.php?page=viewproblem2&cpid=568

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main(){
    int n,m;
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    scanf("%d %d", &n, &m);
    int speedL[100], travel[100];
    int counter = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < a; j++)
            speedL[counter++] = b;
    }
    counter = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < a; j++)
            travel[counter++] = b;
    }
    int maxOver = 0;
    for(int i = 0; i < 100; i++){
        int over = travel[i] - speedL[i];
        maxOver = max(maxOver, over);
    }
    printf("%d", maxOver);
}
