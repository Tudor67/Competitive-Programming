class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        vector<int> prefMin(N);
        prefMin[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMin[i] = min(prefMin[i - 1], nums[i]);
        }

        vector<int> suffMin(N);
        suffMin[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        int minSum = INF;
        for(int i = 1; i + 1 < N; ++i){
            if(prefMin[i - 1] < nums[i] && nums[i] > suffMin[i + 1]){
                minSum = min(minSum, prefMin[i - 1] + nums[i] + suffMin[i + 1]);
            }
        }

        if(minSum == INF){
            minSum = -1;
        }

        return minSum;
    }
};