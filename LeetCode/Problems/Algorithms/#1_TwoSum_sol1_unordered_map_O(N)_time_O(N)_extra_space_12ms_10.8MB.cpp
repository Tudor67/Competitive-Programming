class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        unordered_map<int, int> prevPosOf;
        for(int i = 0; i < N; ++i){
            if(prevPosOf.count(target - nums[i])){
                return {prevPosOf[target - nums[i]], i};
            }
            prevPosOf[nums[i]] = i;
        }
        return {-1, -1};
    }
};