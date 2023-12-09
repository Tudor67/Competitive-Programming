class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remDays = n % 7;
        return weeks * 7 * 8 / 2 + 7 * (weeks - 1) * weeks / 2 +
               remDays * (remDays + 1) / 2 + remDays * weeks;
    }
};