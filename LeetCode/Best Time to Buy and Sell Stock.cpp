// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> v(n);
    v[n - 1] = prices[n - 1];
    int mx = v[n - 1];
    for (int i = n - 2; ~i; --i) {
        v[i] = mx;
        mx = max(mx, prices[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, v[i] - prices[i]);
    }
    return ans;
    }
};

// Another solution

class Solution {
public:
int maxProfit(vector<int>& prices) {
    int mnPrice = INT_MAX, ans = 0;
    for(int &curr : prices){
        mnPrice = min(mnPrice, curr);
        ans = max(ans, curr - mnPrice);
    }
    return ans;
}
};
