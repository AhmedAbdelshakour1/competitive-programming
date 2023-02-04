// https://vjudge.net/problem/UVA-10491#author=0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nl '\n'
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()



int main() {
    int nCow, nCar, nShow;
    while(cin >> nCow >> nCar >> nShow){
        // the chance of picking a cow first and switch to a car
        int total = nCow + nCar;
        double p1 = 1.0 * nCow / total * 1.0 * nCar / (total - nShow - 1);
        // the chance of picking a car first and switch to a cow
        double p2 = 1.0 * nCar / total * 1.0 * (nCar - 1) / (total - nShow - 1);
        cout << fixed << setprecision(5) <<  p1 + p2 << nl;
    }
}













