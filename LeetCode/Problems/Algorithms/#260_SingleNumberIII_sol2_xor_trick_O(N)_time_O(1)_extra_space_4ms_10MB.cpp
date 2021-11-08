class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        
        int fixedMask = numsXOR - (numsXOR & (numsXOR - 1LL));
        int num1 = 0;
        for(int num: nums){
            if(num & fixedMask){
                num1 ^= num;
            }
        }
        
        return {num1, num1 ^ numsXOR};
    }
};