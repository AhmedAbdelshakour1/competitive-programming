// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

class Solution {
public:
bool valid(vector<int> &v, int total, long long time){
    long long ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        ans += time / (1LL * v[i]);
    }
    return ans >= total;
}
long long minimumTime(vector<int>& time, int totalTrips) {
    long long st = 1, end = 1e14;
    while(st < end){
        long long mid = st + (end - st) / 2;
        if(valid(time, totalTrips, mid)) end = mid;
        else st = mid + 1;
    }
    return end;
}
};
