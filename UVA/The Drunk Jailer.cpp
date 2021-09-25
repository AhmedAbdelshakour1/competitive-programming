// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=558

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
#define INF 0x3f3f3f3f
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
ll pow(int b, int p) {   // O(log(p) base 2)
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 //you can solve it by formula (link down)
 //https://r...content-available-to-author-only...t.com/NadaAlaa/CompetitiveProgramming/master/LiveArchive/2557.cpp
 
int main() {
   int t;
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<bool> v(n + 2, true);
        for(int i = 2; i <= n; i++){
            for (int j = i; j <= n; j += i) {
                if(v[j])
                v[j] = false;
                else v[j] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n ; ++i) {
            if(v[i]) ans++;
        }
        printf("%d\n", ans);
    }
}
/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/
