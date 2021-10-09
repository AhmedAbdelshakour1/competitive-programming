// http://www.usaco.org/index.php?page=viewproblem2&cpid=761

/// You just can't beat the person who never gives up
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
 
//void IO(){
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//}
vector<vector<int>> data(3, vector<int>(101));
vector<vector<int>> rates (3, vector<int>(101, 7));
bool highest(int c,  int d){
    int high = max(max(rates[0][d], rates[1][d]), rates[2][d]);
    return rates[c][d] == high;
}
int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N, cow, day, val, changes = 0; string name;
    scanf("%d", &N);
 
    rep(i, 0, N){
        cin >> day >> name >> val;
        if(name == "Bessie") cow = 0;
            if(name == "Elsie") cow = 1;
                if(name == "Mildred") cow = 2;
                data[cow][day] = val;
    }
    for (int c=0; c<3; c++)
        for (int d=1; d<=100; d++)
            rates[c][d] = rates[c][d-1] + data[c][d];
 
        for(int d = 1; d <= 100; d++){
            if (highest(0,d-1) != highest(0,d) ||
                highest(1,d-1) != highest(1,d) ||
                highest(2,d-1) != highest(2,d))
                 changes++;
        }
        printf("%d", changes);
}
