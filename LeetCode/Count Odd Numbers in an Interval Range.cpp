// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

int countOdds(int low, int high) {
     int ans = low % 2 == 1;
     ans += (high - high / 2) - (low - low / 2);
     return ans;
}
