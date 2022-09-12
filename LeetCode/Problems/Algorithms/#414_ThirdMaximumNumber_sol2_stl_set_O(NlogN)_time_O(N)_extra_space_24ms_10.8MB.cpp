class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        if((int)numsSet.size() < 3){
            return *prev(numsSet.end());
        }
        return *prev(prev(prev(numsSet.end())));
    }
};