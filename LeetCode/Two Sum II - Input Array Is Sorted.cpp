// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size() - 1;
        while(a < b){
            if(numbers[a] + numbers[b] > target) b--;
            else if(numbers[a] + numbers[b] < target) a++;
            else {
                return {a + 1, b + 1};
            }
        }
        return {};
    }
};
