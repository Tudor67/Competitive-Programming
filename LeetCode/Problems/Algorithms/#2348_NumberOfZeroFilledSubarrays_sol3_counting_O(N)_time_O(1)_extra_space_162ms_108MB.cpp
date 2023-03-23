class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;

        int consecutiveZeros = 0;
        for(int num: nums){
            if(num == 0){
                consecutiveZeros += 1;
                res += consecutiveZeros;
            }else{
                consecutiveZeros = 0;
            }
        }

        return res;
    }
};