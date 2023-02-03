// https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
string convert(string s, int numRows) {
    if(numRows == 1){
        return s;
    }
    int x = (s.size() + numRows - 1) / numRows;
    int col = 2 * x - 1;
    vector<vector<char>> v(numRows, vector<char> (col));
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < col; ++j) v[i][j] = '%';
    int indx = 0;
    for (int j = 0; j < col; j += 2) {
        for (int i = 0; i < numRows && indx < s.size(); ++i) {
            v[i][j] = s[indx++];
        }
        indx += numRows - 2;
    }
    indx = 0;
    for (int j = 1; j < col; j += 2) {
        if(indx + numRows >= s.size() && indx + 2 * numRows - 2 >= s.size()) break;
        string curr = s.substr(indx + numRows, numRows - 2);
        int indx2 = 0;
        for (int i = numRows - 2; i && indx2 < curr.size(); --i) {
            v[i][j] = curr[indx2++];
        }
        indx += 2 * numRows - 2;
    }
    string st;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < col; ++j) {
            if(v[i][j] == '%') continue;
            st.push_back(v[i][j]);
        }
    }
    return st;
}
};
