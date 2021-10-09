// http://www.usaco.org/index.php?page=viewproblem2&cpid=858

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
 
const int MAX = 1e6 + 1;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n, m, c;
vector<int> v;
bool valid(int time){
    int firstCowsOnBus = v[0], cowsOnBus = 0, numOfBuses = 1;
    for(int i = 0; i < n; i++){
        cowsOnBus++;
        if(cowsOnBus > c || v[i] - firstCowsOnBus > time){
            numOfBuses++;
            if(numOfBuses > m) return false;
            cowsOnBus = 1;
            firstCowsOnBus = v[i];
        }
    }
    return true;
}
int bs(){
    int st = 0, end = 1e9;
    for(int i = 0; i < 30; i++){
        int mid = st + (end - st) / 2;
        if(valid(mid)) end = mid;
        else st = mid;
    }
    return end;
}
int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    v.resize(n);
    for(int &i : v) cin >> i;
    sort(v.begin(), v.end());
    cout << bs() << endl;
}
