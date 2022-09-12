class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        
        int res = 0;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int sum = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[bit];
                }else{
                    sum -= nums[bit];
                }
            }
            if(sum == target){
                res += 1;
            }
        }
        
        return res;
    }
};