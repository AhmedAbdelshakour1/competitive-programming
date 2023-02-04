// https://vjudge.net/problem/UVA-10056#author=0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nl '\n'
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()


const double eps = 1e-9;
int dcomp(double a, double b) { return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1; }

int main() {
    /**
     let p = probability of success , q = 1 - p (failure), Ith = x
     the player might win in his first game -> probability = q^(x - 1) * p
     or in his second game after N loses -> probability = q^(x - 1) * p + q^(x - 1 + n) * p
     or in his second game after 2N loses -> probability = q^(x - 1) * p + q^(x - 1 + n) * p + q^(x -1 + 2*n) and so on...
     keep adding turns till the abs difference is extremely small and doesn't affect the answer
     */
    int t; cin >> t;
    while(t--){
        double p, q; int n, player;
        cin >> n >> p >> player;
        int failure = player - 1;
        q = 1 - p;
        double w = 0;
        while(1){
            double currAdd = pow(q, failure) * p;
            if(!dcomp(w, w + pow(q, failure) * p)) break;
            w += currAdd;
            failure += n;
        }
        cout << fixed << setprecision(4) <<  w << nl;
    }
}













