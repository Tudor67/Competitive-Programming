class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);
        for(int num: nums){
            vis[num] = true;
        }

        int maxLen = 0;
        for(int num: nums){
            int len = 1;
            while(num <= MAX_NUM / num && vis[num * num]){
                num *= num;
                len += 1;
            }
            maxLen = max(maxLen, len);
        }

        if(maxLen <= 1){
            maxLen = -1;
        }

        return maxLen;
    }
};