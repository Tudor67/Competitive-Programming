class Solution {
private:
    int computeMaxLen(int num, unordered_set<int>& numsSet, unordered_map<int, int>& memo){
        if(memo.count(num)){
            return memo[num];
        }

        if(!numsSet.count(num)){
            return 0;
        }
        
        if(num <= INT_MAX / num){
            memo[num] = 1 + computeMaxLen(num * num, numsSet, memo);
        }else{
            memo[num] = 1;
        }
        return memo[num];
    }

public:
    int longestSquareStreak(vector<int>& nums) {
        int maxLen = 1;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        unordered_map<int, int> memo;

        for(int num: numsSet){
            maxLen = max(maxLen, computeMaxLen(num, numsSet, memo));
        }

        if(maxLen <= 1){
            maxLen = -1;
        }

        return maxLen;
    }
};