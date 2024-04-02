class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        int minSum = INF;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    if(nums[i] < nums[j] && nums[j] > nums[k]){
                        minSum = min(minSum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        if(minSum == INF){
            minSum = -1;
        }

        return minSum;
    }
};