class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();

        // maxLen[i]: length of the LIS ending with nums[i]
        vector<int> maxLen(N);
        for(int i = 0; i < N; ++i){
            maxLen[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    maxLen[i] = max(maxLen[i], maxLen[j] + 1);
                }
            }
        }

        return *max_element(maxLen.begin(), maxLen.end());
    }
};