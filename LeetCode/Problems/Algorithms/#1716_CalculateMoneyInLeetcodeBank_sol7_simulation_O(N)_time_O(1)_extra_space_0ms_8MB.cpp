class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int currMoney = 0;
        int mondayMoney = 0;

        for(int day = 1; day <= n; ++day){
            if(day % 7 == 1){
                mondayMoney += 1;
                currMoney = mondayMoney;
            }else{
                currMoney += 1;
            }
            res += currMoney;
        }

        return res;
    }
};