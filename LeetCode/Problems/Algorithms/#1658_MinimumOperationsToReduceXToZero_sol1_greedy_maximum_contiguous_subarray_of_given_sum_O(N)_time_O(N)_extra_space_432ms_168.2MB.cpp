class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        const int EXPECTED_SUM = accumulate(nums.begin(), nums.end(), 0) - x;
        unordered_map<int, int> pos;
        int prefSum = 0;
        pos[prefSum] = -1;
        int maxSubarraySize = INT_MIN;
        for(int i = -1; i < N; ++i){
            prefSum += (i <= -1 ? 0 : nums[i]);
            if(pos.count(prefSum - EXPECTED_SUM)){
                maxSubarraySize = max(i - pos[prefSum - EXPECTED_SUM], maxSubarraySize);
            }
            pos[prefSum] = i;
        }
        return (maxSubarraySize == INT_MIN ? -1 : N - maxSubarraySize);
    }
};