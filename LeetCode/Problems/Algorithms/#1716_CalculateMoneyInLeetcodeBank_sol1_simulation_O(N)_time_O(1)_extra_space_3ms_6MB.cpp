class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        
        int mondayMoney = 0;
        int currentMoney = 0;
        for(int day = 0; day < n; ++day){
            if(day % 7 == 0){
                mondayMoney += 1;
                currentMoney = mondayMoney;
            }else{
                currentMoney += 1;
            }
            res += currentMoney;
        }

        return res;
    }
};