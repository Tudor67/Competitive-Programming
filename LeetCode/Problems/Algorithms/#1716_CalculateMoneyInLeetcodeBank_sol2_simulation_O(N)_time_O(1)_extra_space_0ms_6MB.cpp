class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        for(int day = 0; day < n; ++day){
            res += (day / 7) + (day % 7) + 1;
        }
        return res;
    }
};