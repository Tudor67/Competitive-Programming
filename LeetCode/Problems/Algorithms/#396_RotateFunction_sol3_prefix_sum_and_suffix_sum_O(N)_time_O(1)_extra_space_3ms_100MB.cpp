class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int N = nums.size();

        int currSum = 0;
        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            currSum += (i * nums[i]);
            prefSum += nums[i];
        }
        
        int maxSum = currSum;
        int suffSum = 0;
        for(int i = 1; i < N; ++i){
            prefSum -= nums[N - i];
            currSum = currSum - (N - 1) * nums[N - i] + prefSum + suffSum;
            maxSum = max(maxSum, currSum);
            suffSum += nums[N - i];
        }

        return maxSum;
    }
};