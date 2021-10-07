class Solution {    
public:
    int subsetXORSum(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = floor(log2(MAX_NUM));
        
        int sum = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int ones = 0;
            int zeros = 0;
            for(int num: nums){
                if((num >> bit) & 1){
                    ones += 1;
                }else{
                    zeros += 1;
                }
            }
            int subsetsOfZeros = (1 << zeros);
            int combSumOfOnes = (1 << ones) / 2;
            sum += (1 << bit) * subsetsOfZeros * combSumOfOnes;
        }
        
        return sum;
    }
};