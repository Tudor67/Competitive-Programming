class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n / 7;
        int remDays = n % 7;
        return fullWeeks * 7 * 8 / 2 +
               7 * (fullWeeks - 1) * fullWeeks / 2 +
               remDays * (remDays + 1) / 2 + remDays * fullWeeks;
    }
};