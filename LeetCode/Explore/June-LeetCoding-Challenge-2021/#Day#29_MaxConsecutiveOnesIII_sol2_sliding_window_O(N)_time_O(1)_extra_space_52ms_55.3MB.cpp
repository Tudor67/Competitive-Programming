class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();
        int maxLen = 0;
        int zerosCount = 0;
        for(int i = 0, j = 0; j < N; ++j){
            zerosCount += (nums[j] == 0);
            while(zerosCount > k){
                zerosCount -= (nums[i] == 0);
                i += 1;
            }
            maxLen = max(j - i + 1, maxLen);
        }
        return maxLen;
    }
};