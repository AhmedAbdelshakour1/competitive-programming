// http://www.usaco.org/index.php?page=viewproblem2&cpid=569

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
map<int, map<int, int>> data;
int maxDoses(int milk){
    int counter = 0;
    for(auto i : data) {
        if (i.sec.find(milk) != i.sec.end())
            counter++;
    }
    return counter;
}
int main() {
    freopen ("badmilk.in","r",stdin);
    freopen ("badmilk.out","w",stdout);
    int n, m, d, s;
    cin >> n >> m >> d >> s;
 
    for(int i = 0; i < d; i++){
        int p, milk, t;
        cin >> p >> milk >> t;
        data[p][milk] = t;
    }
    map<int, int> sickData;
    for(int i = 0; i < s; i++){
        int person, time;
        cin >> person >> time;
        for(auto i : data[person]){
            if(i.sec < time)
                sickData[i.fir]++;
        }
    }
    int ans = -1e12;
    for(auto i : sickData){
        if(i.sec == s)
        ans = max(ans, maxDoses(i.fir));
    }
    cout << ans << newline;
}
