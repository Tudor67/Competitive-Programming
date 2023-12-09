class Solution {
public:
    int totalMoney(int n) {
        int res = 0;

        int startMoney = 1;
        while(n >= 1){
            for(int money = startMoney; money < startMoney + min(7, n); ++money){
                res += money;
            }
            n -= 7;
            startMoney += 1;
        }

        return res;
    }
};