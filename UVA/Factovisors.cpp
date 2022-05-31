// https://vjudge.net/problem/UVA-10139#author=0
// https://algorithmist.com/wiki/UVa_10139_-_Factovisors
// https://youtu.be/qHvV6Xjj6e8

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

bool isVowel(char s) {
    s = tolower(s);
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
    return false;
}

ll toInt(string s) {
    ll r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}

string toString(ll number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

bool powerOfTwo(int n) {
    return n && (!(n & (n - 1)));
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll pw(ll a, ll p, int m) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = (a % m * result % m) % m;
        a = (a % m * a % m) % m;;
        p >>= 1;
    }
    return result % m;
}

//.........................................(^_^)............................................//
ll n, m;
map<ll, ll> primeFactors;
void pFactors(){
    for (ll i = 2; i * i <= m; i += 1 + (i & 1)) {
        while(m % i == 0) primeFactors[i]++, m /= i;
    }
    if(m > 1) primeFactors[m]++;
}
ll getPower(ll p){
    ll ans = 0;
    for (ll power = p; power <= n; power *= p)
        ans += n / power;
    return ans;
}
int main() {
   while(scanf("%lld %lld", &n, &m) == 2){
       primeFactors.clear();
       if(!m){
           printf("%lld does not divide %lld!\n", m, n);
           continue;
       }
       ll tem = m;
       pFactors();
       int valid = 1;
       for(auto x : primeFactors){
           if(x.second > getPower(x.first)){
               valid = 0;
               break;
           }
       }
       if(valid)
           printf("%lld divides %lld!\n", tem, n);
       else printf("%lld does not divide %lld!\n", tem, n);
   }
}
