#include <bits/stdc++.h>
#include <fstream>

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
class MergersDivTwo {
public:
    double findMaximum(vector<int> revenues, int k) {
        int n = len(revenues);
        int prefix[n];
        sort(all(revenues));
        prefix[0] = revenues[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + revenues[i];
        double dp[n];
        for (int i = 0; i < n; ++i)
            dp[i] = 1.0 * prefix[i] / (i + 1);

        for (int i = k; i < n; ++i)
            for (int j = i + (k - 1) - 1, cnt = k; j < n; ++j, ++cnt)
                dp[j] = max(dp[j], 1.0 * (dp[i - 1] + prefix[j] - prefix[i - 1]) / cnt);

        return dp[n - 1];
    }
};

int main() {

}
