// https://leetcode.com/problems/k-closest-points-to-origin/description/

// Partial Sort
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const auto &x, const auto &y){
            return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1];
        };
        nth_element(points.begin(), points.begin() + k - 1, points.end(), cmp);
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};


// Another Solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> mp;
        int n = points.size(), x, y;
        for(int i = 0; i < n; i++){
            x = points[i][0];
            y = points[i][1];
            mp.insert({x * x + y * y, points[i]});
        }
        vector<vector<int>> ans;
        for(auto &x : mp){
            if(ans.size() == k) break;
            ans.push_back(x.second);
        }
        return ans;
    }
};
