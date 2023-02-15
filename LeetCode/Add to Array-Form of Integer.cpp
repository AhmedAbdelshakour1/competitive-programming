// https://leetcode.com/problems/add-to-array-form-of-integer/description/

vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> ans;
    int indx = num.size() - 1, curr = 0;
    while(k || curr || ~indx){
        if(indx >= 0) curr += num[indx--];
        curr += k % 10 ;
        k /= 10;
        ans.push_back(curr % 10);
        curr /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
