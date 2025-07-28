class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;

        int subsetMaxOR = 0;
        for(int num: nums){
            subsetMaxOR |= num;
        }

        int res = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int subsetOR = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    subsetOR |= nums[bit];
                }
            }
            if(subsetOR == subsetMaxOR){
                res += 1;
            }
        }

        return res;
    }
};