// http://www.usaco.org/index.php?page=viewproblem2&cpid=989

/// You just can't beat the person who never gives up.
#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
typedef long long ll;
typedef unsigned int uit;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define newline "\n"
#define fir first
#define sec second
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
 
 
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int k, n;
int solve(int dist){
    int distUP = 0, distDown = 0, time = 0;
    for(int speed = 1; ; speed++){
        distUP += speed;
        time++;
        if(distUP + distDown >= k) return time;
        if(speed >= dist){
            distDown += speed;
            time++;
            if(distUP + distDown >= k) return time;
        }
    }
}
int main(){
    IO();
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cout << solve(x) << newline;
    }
}
