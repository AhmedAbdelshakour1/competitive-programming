// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
vector<int> v;
bool valid(int mid, int cows, int n){
    int curr = v[1], ans = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] - curr >= mid){
            ans++;
            curr = v[i];
        }
    }
    return ans >= cows;
}
int BS(int n, int c){
    int st = 1, end = 1e9;
    while(st + 1< end){
        int mid = st + (end - st) / 2;
        if(valid(mid, c, n)) st = mid;
        else end = mid;
    }
    return st;
}
int main() {
    int t; scanf("%d", &t);
    while(t--){
        int n, c;
        scanf("%d %d", &n, &c);
        v.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        printf("%d\n", BS(n, c));
        v.clear();
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
