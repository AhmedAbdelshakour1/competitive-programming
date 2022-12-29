// https://leetcode.com/problems/two-sum/
//...............................Cpp........................................//
class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        int x = target - nums[i];
        if(mp.count(x)){
            return {mp[x], i};
        }
        mp[nums[i]] = i;
    }
    return {0, 0};
}
};


//...............................C#........................................//
public class Solution {
public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> mp = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            int need = target - nums[i];
            if (mp.ContainsKey(need)) return new[] { mp[need], i };
            if (!mp.ContainsKey(nums[i])) mp[nums[i]] = i;
        }
        return new int[2];
    }
}
