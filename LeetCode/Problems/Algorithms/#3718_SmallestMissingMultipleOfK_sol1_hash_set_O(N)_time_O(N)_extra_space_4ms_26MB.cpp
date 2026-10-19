class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int multiple = k;
        while(numsSet.contains(multiple)){
            multiple += k;
        }
        return multiple;
    }
};