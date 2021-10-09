// http://www.usaco.org/index.php?page=viewproblem2&cpid=712

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define forl(i, a, n) for(int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
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
 
void IO(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
bool intersect(pair<int, int> &start, pair<int, int> &end){
    return (start.fir < end.fir && end.fir < start.sec && start.sec < end.sec) ||
           (end.fir < start.fir && start.fir < end.sec && end.sec < start.sec);
}
int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    IO();
    string s;
    cin >> s;
    pair <int, int> locations[26];
    for(int i = 1; i <= s.size(); i++){
        if(!(locations[s[i-1] - 'A'].fir)) locations[s[i-1] - 'A'].fir = i;
        else locations[s[i-1] - 'A'].sec = i;
    }
    int sol = 0;
    for (char i = 'A'; i <= 'Z'; i++){
        for (char j = i+1; j <= 'Z'; j++)  {
            if (intersect(locations[i - 'A'], locations[j - 'A']))
                sol++;
        }
    }
            cout << sol;
}
