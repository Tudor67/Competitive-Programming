class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        const int N = nums.size();
        
        int maxXOR = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])){
                    maxXOR = max(maxXOR, nums[i] ^ nums[j]);
                }
            }
        }
        
        return maxXOR;
    }
};