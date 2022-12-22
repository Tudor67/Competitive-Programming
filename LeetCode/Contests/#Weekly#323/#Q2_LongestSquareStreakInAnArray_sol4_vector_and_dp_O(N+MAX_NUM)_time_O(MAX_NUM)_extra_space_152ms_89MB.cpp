class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        // maxLen[num]: length of the longest square streak when the last element is num
        vector<int> maxLen(MAX_NUM + 1);
        for(int num: nums){
            maxLen[num] = 1;
        }

        for(int num = 2; num * num <= MAX_NUM; ++num){
            if(maxLen[num] >= 1 && maxLen[num * num] >= 1){
                maxLen[num * num] = maxLen[num] + 1;
            }
        }

        int res = *max_element(maxLen.begin(), maxLen.end());
        if(res < 2){
            res = -1;
        }

        return res;
    }
};