class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        
        int duplicate = -1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] == nums[i]){
                duplicate = nums[i];
                break;
            }
        }
        
        int targetTotalSum = N * (N + 1) / 2;
        int currentTotalSum = accumulate(nums.begin(), nums.end(), 0);
        int missing = targetTotalSum - (currentTotalSum - duplicate);
        
        return {duplicate, missing};
    }
};