// http://www.usaco.org/index.php?page=viewproblem2&cpid=917

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
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int N, a = -100000, b = 1000000;
    scanf("%d", &N);
    string s[100];
    int A[100], B[100];
    rep(i, 0, N) cin >> s[i] >> A[i] >> B[i];
    //before 1...we go backwards
    for(int i = N - 1; i >= 0; i--){
        if(s[i] == "none"){
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (s[i] == "off") {
            a += A[i];
            b += B[i];
        }
        if(s[i] == "on"){
            a -= B[i];
            a = max(0, a);
            b -= A[i];
        }
 
    }
    printf("%d %d\n", a, b);
    a = -100000, b = 1000000;
    //after N...
    rep(i, 0, N){
        if(s[i] == "none"){
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if(s[i] == "off"){
            a -= B[i];
            a = max(0, a);
            b -= A[i];
        }
        if (s[i] == "on") {
            a += A[i];
            b += B[i];
        }
    }
    printf("%d %d", a, b);
}
