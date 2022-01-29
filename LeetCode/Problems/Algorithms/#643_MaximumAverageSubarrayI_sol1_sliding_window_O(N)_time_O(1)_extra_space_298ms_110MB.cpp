class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            if(i >= k){
                sum -= nums[i - k];
            }
            if(i >= k - 1){
                maxSum = max(maxSum, sum);
            }
        }
        
        return (1.0 * maxSum / k);
    }
};