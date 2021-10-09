// https://atcoder.jp/contests/abc164/tasks/abc164_d

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
    string s;
    cin >> s;
    int ans = 0, sum = 0, power = 1;
    vector<int> v(2019);
    v[0] = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        int dig = s[i] - '0';
        sum = (sum + dig * power) % 2019;
        ans += v[sum];
        power = power * 10 % 2019;
        v[sum]++;
    }
    cout << ans;
}
