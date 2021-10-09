// http://www.usaco.org/index.php?page=viewproblem2&cpid=567

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a > c){
        int tempA = a;
        a = c;
        c = tempA;
 
        int tempB = d;
        d = b;
        b = tempB;
    }
    //check there is exit overlap
    //not overlap
    if(c >= b) printf("%d" ,((b - a) + (d - c)));
    // overlap
    else{
        if(d >= b) printf("%d", (d- a));
        else printf("%d", (b - a));
    }
    }
    //another sol
    //you can calculate totol length and subtract the intersection
    //intersection = max(0, min(b, d) - max(a, c))) that give 0 if there no intersection
    //the total sol is (b - a) + (d - c) - max(0, min(b, d) - max(a, c)))
