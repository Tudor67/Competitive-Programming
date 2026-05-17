class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int N = nums.size();

        int currSum = 0;
        int totalSum = 0;
        for(int i = 0; i < N; ++i){
            currSum += (i * nums[i]);
            totalSum += nums[i];
        }
        
        int maxSum = currSum;
        for(int i = 1; i < N; ++i){
            currSum = currSum - N * nums[N - i] + totalSum;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};