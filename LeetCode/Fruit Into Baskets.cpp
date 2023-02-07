// https://leetcode.com/problems/fruit-into-baskets/description/

int totalFruit(vector<int>& fruits) {
    int f = -1, s = -1, cntF = 0, cntS = 0, ans = 0;
    vector<int> diff(fruits.size(), 1);
    for (int i = 1; i < diff.size(); ++i) {
        if(fruits[i] == fruits[i - 1]) diff[i] += diff[i - 1];
    }
    for(int i = 0; i < fruits.size(); i++){
        if(f == -1){
            f= fruits[i], cntF++;
            continue;
        }
        if(s == -1 && fruits[i] != f){
            s = fruits[i], cntS++;
            continue;
        }

        if(fruits[i] == f) cntF++;
        else if(fruits[i] == s) cntS++;


        else {
            ans = max(ans, cntF + cntS);
            cntF = diff[i - 1];
            cntS = 1;
            f = fruits[i - 1];
            s = fruits[i];
        }
    }
    return max(ans, cntF + cntS);
}
