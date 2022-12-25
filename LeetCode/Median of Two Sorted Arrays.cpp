// https://leetcode.com/problems/median-of-two-sorted-arrays/?fbclid=IwAR1lGHRJ1f6LGELXqaFSFEgbPe3RVhDewGYv7aCyNywqgu9VryfrbxAuX_8

class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if(n > m) return findMedianSortedArrays(nums2, nums1);
    int st = 0, end = n, partA, partB, maxA, minA, maxB, minB;
    while(st <= end){
        partA = st + (end - st) / 2;
        partB = (n + m + 1) / 2 - partA;
        maxA = partA == 0 ? -1 : nums1[partA - 1];
        minA = partA == n ? INT_MAX : nums1[partA];
        maxB = partB == 0 ? -1 : nums2[partB - 1];
        minB = partB == m ? INT_MAX : nums2[partB];
        if(maxA <= minB && maxB <= minA){
            if((n + m) & 1) return max(maxA, maxB) * 1.0;
            else return (max(maxA, maxB) + min(minA, minB)) / 2.0;
        }else if(maxA > minB) end = partA - 1;
        else if(maxB > minA) st = partA + 1;
    }
    return 0.0;
}
};
