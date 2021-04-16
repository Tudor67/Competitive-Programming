class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        
        // maxLen[i]: maximum length of a strictly increasing subsequence with last element nums[i]
        vector<int> maxLen(N, 1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    maxLen[i] = max(1 + maxLen[j], maxLen[i]);
                }
            }
        }
        
        return *max_element(maxLen.begin(), maxLen.end());
    }
};