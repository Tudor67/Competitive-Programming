class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children){
            return -1;
        }

        int c8 = min((money - children) / 7, children);
        int c1 = children - c8;
        int remMoney = money - 8 * c8 - c1;
        if((c1 == 0 && remMoney >= 1) ||
           (c1 == 1 && remMoney == 3)){
            c8 -= 1;
        }

        return c8;
    }
};