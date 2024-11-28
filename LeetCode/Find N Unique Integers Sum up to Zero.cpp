// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/

class Solution {
public:
    vector<int> sumZero(int n) {
        // if n even -> add x and -x, in case of n odd -> add zero 
        vector<int> ans;
        if(n & 1) ans.push_back(0), n--;
        for(int i = 1; i <= n / 2; i++) ans.push_back(i), ans.push_back(-i);
        return ans;
    }
};
