class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(int num: numsSet){
            int len = 1;
            while(num <= INT_MAX / num && numsSet.count(num * num)){
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