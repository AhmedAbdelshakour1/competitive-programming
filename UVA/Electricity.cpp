// https://vjudge.net/problem/UVA-12148

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
bool leap(int year){
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;
    return false;
}
bool check_month(int m){
    if(m == 4 || m == 6 || m == 9 || m == 11) return true;
    return false;
}
bool check_month2(int d, int m, int y){
    if((m == 2 && leap(y) && d == 29) || (m == 2 && !leap(y) && d == 28)) return true;
    return false;
}
bool begin_month(int d, int m, int y){
    if(((d == 31 && !check_month(m)) || (d == 30 && check_month(m)) ||
        check_month2(d, m, y))) return true;
    return false;
}
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        vector<vector<int>> v(n, vector<int>(4));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &v[i][j]);
            }
        }
        ll ans = 0, c = 0;
        for (int i = 1; i < n; i++) {
            if (v[i][2] == v[i - 1][2]) {
                if ((v[i][0] == 1 && (begin_month(v[i - 1][0], v[i - 1][1], v[i - 1][2])) && v[i][1] - 1 == v[i - 1][1]) || (v[i][0] - 1 == v[i - 1][0] && v[i][1] == v[i - 1][1])) {
                    c++;
                    ans += v[i][3] - v[i - 1][3];
                }
            }else if(v[i][2] - 1 == v[i - 1][2]){
                if(v[i][0] == 1 && v[i][1] == 1 && v[i - 1][0] == 31 && v[i - 1][1] == 12){
                    c++;
                    ans += v[i][3] - v[i - 1][3];
                }
            }
        }
        printf("%lld %lld\n", c, ans);
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
