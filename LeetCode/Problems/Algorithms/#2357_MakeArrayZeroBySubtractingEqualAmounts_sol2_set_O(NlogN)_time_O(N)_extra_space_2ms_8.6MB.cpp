class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        numsSet.erase(0);
        return numsSet.size();
    }
};