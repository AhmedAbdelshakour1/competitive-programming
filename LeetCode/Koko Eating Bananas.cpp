// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    bool valid(vector<int> &v, int h, long long k){
        long long b = 0;
        for(int &x : v){
            b += 1LL* x / k + (x % k != 0);
        }
        return b <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long st = 1, end = 1e13 + 1;
        while(st < end){
            long long mid = st + (end - st) / 2;
            if(valid(piles, h, mid)) end = mid;
            else st = mid + 1;
        }
        return end;
    }
};
