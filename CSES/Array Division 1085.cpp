// https://cses.fi/problemset/task/1085/

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
ll n, k, sum = 0;
vector<ll> v;
bool valid(ll mx){
    ll s = 0, counter = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > mx) return false;
        if(s + v[i] > mx){
            counter++;
            s = 0;
        }
        s += v[i];
 
    }
    if(s > 0) counter++;
    return counter <= k;
}
ll bs(){
    ll st = 1, end = sum;
    while(end > st + 1){ // at most x >>>>> y > x  00001111
        ll mid = st + (end - st) / 2;
        if(valid(mid)) end = mid;
        else st = mid;
    }
    return end;
}
int main() {
    IO();
    cin >> n >> k;
    v.resize(n);
    for(ll &i : v){
        cin >> i;
        sum += i;
    }
    cout << bs() << endl;
}
