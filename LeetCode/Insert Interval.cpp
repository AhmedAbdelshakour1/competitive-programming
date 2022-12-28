// https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size(), indx = 0;

    while(indx < n && intervals[indx][1] < newInterval[0]) {
        ans.push_back(intervals[indx]);
        indx++;
    }
     while(indx < n && intervals[indx][0] <= newInterval[1]){
         newInterval[0] = min(newInterval[0], intervals[indx][0]);
         newInterval[1] = max(newInterval[1], intervals[indx][1]);
         indx++;
     }
     ans.push_back(newInterval);
     while(indx < n) ans.push_back(intervals[indx]), indx++;
    return ans;
 }
};
