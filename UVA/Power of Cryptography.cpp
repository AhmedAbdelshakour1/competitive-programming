// https://vjudge.net/problem/UVA-113#author=0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    double n, p;
    while(scanf("%lf %lf", &n, &p) != EOF){
        printf("%.0lf\n", pow(p, 1 / n)) ;
    }
}
