class Solution {
private:
    int rangeSum(int l, int r){
        return max(0, r * (r + 1) / 2 - (l - 1) * l / 2);
    }

public:
    int totalMoney(int n) {
        int fullWeeks = n / 7;
        int remDays = n - fullWeeks * 7;
        return fullWeeks * rangeSum(1, 7) + 7 * rangeSum(1, fullWeeks - 1) +
               rangeSum(fullWeeks + 1, fullWeeks + remDays);
    }
};