// http://www.usaco.org/index.php?page=viewproblem2&cpid=591

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned long long int ulli;
 
int main() {
    int bB, bA, sB, sA, gB, gA, pA, pB;
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    scanf("%d %d %d %d %d %d %d %d", &bB, &bA, &sB, &sA, &gB, &gA, &pB, &pA);
    int GTP = pA - pB;
    int STG = gA - gB + pA - pB;
    int BTS = sA - sB + gA - gB + pA - pB;
    cout << BTS << "\n" << STG << "\n" << GTP;
 }
