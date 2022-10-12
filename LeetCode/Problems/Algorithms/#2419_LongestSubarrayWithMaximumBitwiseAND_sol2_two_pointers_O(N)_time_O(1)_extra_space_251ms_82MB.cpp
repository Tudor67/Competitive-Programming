class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int maxLen = 0;
        int len = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] == MAX_NUM){
                len += 1;
                maxLen = max(maxLen, len);
            }else{
                len = 0;
            }
        }
        
        return maxLen;
    }
};