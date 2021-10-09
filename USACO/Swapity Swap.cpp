// http://www.usaco.org/index.php?page=viewproblem2&cpid=1013

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef long long ll;
 
int main() {
    IO();
    freopen ("swap.in" , "r", stdin);
    freopen ("swap.out", "w", stdout);
    int n, k, a1, a2 ,b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i + 1;
    int count = 0;
    do{
        reverse(v.begin() + a1 - 1, v.begin() + a2);
        reverse(v.begin() + b1 - 1, v.begin() + b2);
        count++;
    }while(!is_sorted(v.begin(), v.end()));
 
    k %= count;
    while(k--){
        reverse(v.begin() + a1 - 1, v.begin() + a2);
        reverse(v.begin() + b1 - 1, v.begin() + b2);
    }
    for(int i = 0; i < n; i++)
        cout << v[i] << "\n";
}
