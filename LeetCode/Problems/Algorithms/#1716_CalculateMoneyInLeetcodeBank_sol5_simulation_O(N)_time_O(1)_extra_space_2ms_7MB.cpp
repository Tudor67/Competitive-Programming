class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            res += 1 + (i - 1) % 7 + (i - 1) / 7;
        }
        return res;
    }
};