class Solution {
private:
    int sign(int num){
        if(num < 0){
            return -1;
        }else if(num == 0){
            return 0;
        }
        return 1;
    }

public:
    int arraySign(vector<int>& nums) {
        int prodSign = 1;
        for(int num: nums){
            prodSign *= sign(num);
        }
        return prodSign;
    }
};