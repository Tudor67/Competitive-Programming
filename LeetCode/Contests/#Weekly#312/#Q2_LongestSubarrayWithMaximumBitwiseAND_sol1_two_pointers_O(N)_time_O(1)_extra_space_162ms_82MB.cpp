class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int maxLen = 0;
        int startPos = 0;
        while(startPos < N){
            int endPos = startPos;
            while(endPos < N && nums[endPos] == MAX_NUM){
                endPos += 1;
            }
            maxLen = max(maxLen, endPos - startPos);
            startPos = max(startPos + 1, endPos);
        }
        
        return maxLen;
    }
};