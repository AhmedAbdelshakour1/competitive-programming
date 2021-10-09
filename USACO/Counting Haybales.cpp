// http://www.usaco.org/index.php?page=viewproblem2&cpid=666

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int MAX = 1e6 + 1;
int N,Q;
vector<int> v;
int count(int x){
    int s = -1, e = N;
    while(e > s + 1){
        int mid = s + (e - s) / 2;
        if(v[mid] <= x) s = mid;
        else e = mid;
    }
    return s;
}
int main() {
    IO();
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> N >> Q;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(begin(v),end(v));
    for (int i = 0; i < Q; ++i) {
        int A,B; cin >> A >> B;
        cout << count(B) - count(A - 1) << "\n";
    }
 
}
