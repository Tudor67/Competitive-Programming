class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        unordered_map<int, int> lastIndexOf;
        for(int i = 0; i < N; ++i){
            if(lastIndexOf.count(target - nums[i])){
                return {lastIndexOf[target - nums[i]], i};
            }
            lastIndexOf[nums[i]] = i;
        }
        return {};
    }
};