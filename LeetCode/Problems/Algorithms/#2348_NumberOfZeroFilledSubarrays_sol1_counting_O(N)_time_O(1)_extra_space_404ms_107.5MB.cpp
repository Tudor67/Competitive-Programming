class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        
        int consecutiveZeros = 0;
        for(int num: nums){
            if(num == 0){
                consecutiveZeros += 1;
            }else{
                consecutiveZeros = 0;
            }
            res += consecutiveZeros;
        }
        
        return res;
    }
};