class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prodSign = 1;
        for(int num: nums){
            if(num == 0){
                return 0;
            }
            if(num < 0){
                prodSign = -prodSign;
            }
        }
        return prodSign;
    }
};