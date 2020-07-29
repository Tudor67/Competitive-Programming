class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num1_xor_num2 = 0;
        for(int num: nums){
            num1_xor_num2 ^= num;
        }
        
        int mask1 = num1_xor_num2 & (num1_xor_num2 - 1) ^ num1_xor_num2;
        int num1 = 0;
        for(int num: nums){
            if(num & mask1){
                num1 ^= num;
            }
        }
        
        return {num1, num1 ^ num1_xor_num2};
    }
};