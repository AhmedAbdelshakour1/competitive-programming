// https://leetcode.com/problems/check-if-n-and-its-double-exist/description/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ust;
        for(int &x : arr){
            if(ust.count(2 * x) || ust.count(x / 2) && !(x & 1)) return true;
            ust.insert(x);
        }
        return false;
    }
};
