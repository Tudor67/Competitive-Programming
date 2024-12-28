class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> prevWays = {{0, 1}};
        unordered_map<int, int> currWays;
        for(int num: nums){
            currWays.clear();
            for(auto [sum, sumWays]: prevWays){
                currWays[sum - num] += sumWays;
                currWays[sum + num] += sumWays;
            }
            prevWays = currWays;
        }
        return currWays[target];
    }
};