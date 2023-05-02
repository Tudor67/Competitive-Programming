class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children){
            return -1;
        }

        int l = 0;
        int r = children;
        while(l != r){
            int mid = (l + r + 1) / 2;
            int c8 = mid;
            int c1 = children - c8;
            if((8 * c8 + c1 <= money) &&
               !(c1 == 1 && money - 8 * c8 == 4) &&
               !(c1 == 0 && money - 8 * c8 >= 1)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};