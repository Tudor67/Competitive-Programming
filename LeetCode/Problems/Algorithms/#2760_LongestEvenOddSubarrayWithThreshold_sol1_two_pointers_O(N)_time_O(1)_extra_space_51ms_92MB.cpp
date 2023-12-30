class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        const int N = nums.size();

        int maxLen = 0;
        
        int i = 0;
        while(i < N){
            if(nums[i] % 2 == 0 && nums[i] <= threshold){
                int len = 1;
                while(i + 1 < N && nums[i] % 2 != nums[i + 1] % 2 && nums[i + 1] <= threshold){
                    len += 1;
                    i += 1;
                }
                maxLen = max(maxLen, len);
            }
            i += 1;
        }

        return maxLen;
    }
};