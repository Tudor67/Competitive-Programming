class Solution {
private:
    int solve(int num, unordered_set<int>& numsSet, unordered_map<int, int>& memo){
        if(!memo.count(num)){
            if(numsSet.count(num)){
                memo[num] = 1 + solve(num - 1, numsSet, memo);
            }else{
                memo[num] = 0;
            }
        }
        return memo[num];
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        unordered_map<int, int> memo; // memo[x]: length of the longest sequence with last element x
        int maxLength = 0;
        for(int num: numsSet){
            int maxLengthAtNum = solve(num, numsSet, memo);
            maxLength = max(maxLengthAtNum, maxLength);
        }
        return maxLength;
    }
};