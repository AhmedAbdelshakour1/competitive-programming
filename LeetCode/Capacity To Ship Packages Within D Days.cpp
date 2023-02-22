// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
bool valid(vector<int> &v, int d, int sz){
    int cnt = 1, sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] > sz) return false;
        if(sum + v[i] <= sz) {
            sum += v[i];
        }
        else {
            sum = v[i];
            cnt++;
        }
    }
    return cnt <= d;
}
int shipWithinDays(vector<int>& weights, int days) {
     int st = 1, end = accumulate(weights.begin(), weights.end(), 0);
     while(st < end){
         int mid = st + (end - st) / 2;
         if(valid(weights, days, mid)) end = mid;
         else st = mid + 1;
     }
     return end;
}
};
