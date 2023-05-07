// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int n;
    vector<int> dp, c;
    int solve(int indx){
        if(indx >= n) return 0;
        int &ret = dp[indx];
        if(~ret) return ret;
        ret = c[indx] + min(solve(indx + 1), solve(indx + 2));
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n, -1);
        c = cost;
        return min(solve(0), solve(1));
    }
};
