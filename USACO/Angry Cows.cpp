// http://www.usaco.org/index.php?page=viewproblem2&cpid=594

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
int n, k;
vector<int> v;
bool valid(int r){
    int counter = 0, i = 0;
    while(i < n) {
        int curPos = v[i];
        while (i < n && v[i] <= curPos + 2 * r)
            i++;
        counter++;
    }
    return counter <= k;
}
int bs(){
    int st = 0, end = 1e9;
    while(st + 1 < end){
        int mid = st + (end - st) / 2;
        valid(mid) ? end = mid : st = mid;
    }
    return end;
}
int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    IO();
    cin >> n >> k;
    v.resize(n);
    for(int &i : v) cin >> i;
    sort(v.begin(), v.end());
 
    cout << bs();
}
