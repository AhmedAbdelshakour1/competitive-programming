// https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    using ll = long long;
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        vector<ll> p = {2, 3, 5};
        pq.push(1);
        unordered_set<ll> ust = {1};
        ll uglyNum = 1;
        for (int i = 0; i < n; ++i) {
            uglyNum = pq.top();
            pq.pop();
            for (int pr : p) {
                if(!ust.count(uglyNum * pr)) {
                    pq.push(uglyNum * pr);
                    ust.insert(uglyNum * pr);
                }
            }
        }
    return uglyNum;
  }
};
