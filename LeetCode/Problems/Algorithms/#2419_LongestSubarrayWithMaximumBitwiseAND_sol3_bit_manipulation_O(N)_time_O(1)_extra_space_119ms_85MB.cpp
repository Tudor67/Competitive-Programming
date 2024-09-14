class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int maxLen = 0;
        int len = 0;
        for(int num: nums){
            if(num == MAX_NUM){
                len += 1;
            }else{
                len = 0;
            }
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};