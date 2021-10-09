// http://www.usaco.org/index.php?page=viewproblem2&cpid=713

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
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
 int n, a, b;
 scanf("%d", &n);
 vector<pii> v(n);
 rep(i, 0, n){
     scanf("%d %d", &a, &b);
     v[i] = {a, b};
 }
 sort(v.begin(), v.end());
 int time = v[0].fir + v[0].second;
 rep(i, 0, n - 1){
     if(time <= v[i + 1].fir) time = v[i + 1].fir + v[i + 1].sec;
     else time += v[i + 1].sec;
 }
 
 cout << time;
}
