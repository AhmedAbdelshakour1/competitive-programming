// https://vjudge.net/problem/UVA-713

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045
#define INF 0x3f3f3f3f
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
 
ll pow(int b, int p) {   // O(log(p) base 2)
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
 
int main() {
   int t;
   cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        reverse(all(a));
        reverse(all(b));
        int sz = max(len(a), len(b));
        deque<int> da, db, dc;
        if(len(a) > len(b)) {
            int curr = len(a) - len(b);
            while (curr != 0) {
                db.push_front(0);
                curr--;
            }
        }else if(len(a) < len(b)) {
            int curr = len(b) - len(a);
            while (curr != 0) {
                da.push_front(0);
                curr--;
            }
        }
 
        for(char & i : a) {
            da.push_back(i - '0');
        }
        for(char & i : b) {
            db.push_back(i - '0');
        }
        for(int i = sz - 1; i >= 0; i--){
            int sum = da[i] + db[i];
            if(i == 0){
                while(sum != 0){
                    dc.push_front(sum % 10);
                    sum /= 10;
                }
            }
            if(sum >= 10 && i != 0){
                dc.push_front(sum % 10);
                sum /= 10;
                da[i - 1] += + sum;
            }else {
                if(i != 0)
                dc.push_front(sum);
            }
        }
 
        reverse(all(dc));
        for (int i : dc) {
            if(!i) dc.pop_front();
            else break;
        }
        for (int i : dc) {
            cout << i;
        }
        cout << endl;
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
