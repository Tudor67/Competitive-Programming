class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;

        int maxOR = 0;
        for(int num: nums){
            maxOR |= num;
        }

        int maxSubsets = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int subsetOR = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    subsetOR |= nums[bit];
                }
            }
            if(subsetOR == maxOR){
                maxSubsets += 1;
            }
        }

        return maxSubsets;
    }
};