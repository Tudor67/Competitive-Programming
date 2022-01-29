class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_ONES = count(nums.begin(), nums.end(), 1);
        
        int maxOnes = 0;
        int ones = 0;
        for(int i = 0; i < 2 * N; ++i){
            ones += nums[i % N];
            if(i >= TOTAL_ONES){
                ones -= nums[(i - TOTAL_ONES) % N];
            }
            maxOnes = max(maxOnes, ones);
        }
        
        return TOTAL_ONES - maxOnes;
    }
};