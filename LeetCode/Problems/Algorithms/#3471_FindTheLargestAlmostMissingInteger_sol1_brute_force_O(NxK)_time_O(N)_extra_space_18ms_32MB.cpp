class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> subarrayCount;
        unordered_set<int> vis;

        for(int i = 0; i < N - k + 1; ++i){
            vis.clear();
            for(int j = i; j < i + k; ++j){
                if(!vis.contains(nums[j])){
                    vis.insert(nums[j]);
                    subarrayCount[nums[j]] += 1;
                }
            }
        }

        int res = -1;
        for(const auto& [num, numSubarrayCount]: subarrayCount){
            if(numSubarrayCount == 1){
                res = max(res, num);
            }
        }

        return res;
    }
};