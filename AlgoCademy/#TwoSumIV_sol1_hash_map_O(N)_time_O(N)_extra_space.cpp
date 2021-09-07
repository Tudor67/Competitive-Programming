class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        unordered_map<int, int> idxOf;
        for(int i = 0; i < N; ++i){
            if(idxOf.find(target - nums[i]) != idxOf.end()){
                return {idxOf[target - nums[i]], i};
            }
            idxOf[nums[i]] = i;
        }
        return {-1, -1};
    }
};