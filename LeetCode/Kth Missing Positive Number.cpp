// https://leetcode.com/problems/kth-missing-positive-number/description/

// O(log(n))

class Solution {
public:
int findKthPositive(vector<int>& arr, int k) {
    int st = 0, end = arr.size() - 1;
    while(st <= end){
        int mid = st + (end - st) / 2;
        if(arr[mid] - (mid + 1) < k) st = mid + 1;
        else end = mid - 1;
    }
    return st + k;
}
};

// Another solution 

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int curr = 0;
    vector<int> cnt(2222);
    for (int i = 0; i < arr.size(); ++i) {
        cnt[arr[i]] = 1;
    }
    for (int i = 1; i < 2222; ++i) {
        if(!cnt[i]) curr++;
        if(curr == k) return i;
    }
    return 0;
}
};
