class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        int val = original;
        while(numsSet.count(val)){
            val *= 2;
        }

        return val;
    }
};