// http://www.usaco.org/index.php?page=viewproblem2&cpid=964

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
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
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    set<string> st;
    for(int len = 1; len <= n; len++){
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(!st.count(s.substr(i, len))) st.insert(s.substr(i, len));
            else {
                st.clear();
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("%d", len);
            return 0;
        }
    }
}
