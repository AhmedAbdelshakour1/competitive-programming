// https://vjudge.net/problem/UVA-10242

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
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e18;
const double eps = 1e-9;

int dcomp(double a, double b) {
    return fabs(a - b) <= eps ? 0 : a < b ? 1 : -1;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll pw(ll a, ll p) {
    if (p == 0) return 1;
    ll result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

//.....................................................................................//
set<pair<double, double>> st;
double x[4], y[4];
int main() {
    while (scanf("%lf %lf", &x[0], &y[0]) != EOF){
        for (int i = 1; i < 4; i++) scanf("%lf %lf", &x[i], &y[i]); 
        st.clear();
        double cx, cy;
        for (int i = 0; i < 4; ++i) {
            if (st.find({x[i], y[i]}) != st.end()) {
                cx = x[i], cy = y[i];
                st.erase({x[i], y[i]});
            } else st.insert({x[i], y[i]});
        }
        //translation to origin
        auto f = st.begin();
        auto s = ++st.begin();
        double px = f->first + s->first - cx;
        double py = f->second + s->second - cy;
        printf("%.3lf %.3lf\n", px, py);
      
      //Another solution
      /**
      if(x1 == x3 && y1 == y3)
			printf("%.3lf %.3lf\n", (x2+x4)-x1, (y2+y4)-y1);
		else if(x1 == x4 && y1 == y4)
			printf("%.3lf %.3lf\n", (x2+x3)-x1, (y2+y3)-y1);
		else if(x2 == x3 && y2 == y3)
			printf("%.3lf %.3lf\n", (x1+x4)-x2, (y1+y4)-y2);
		else
			printf("%.3lf %.3lf\n", (x1+x3)-x2, (y1+y3)-y2);
      **/
    }
}
