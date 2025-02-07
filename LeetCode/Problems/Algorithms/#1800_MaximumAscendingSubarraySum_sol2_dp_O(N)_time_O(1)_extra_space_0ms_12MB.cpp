class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int N = nums.size();

        int maxSum = 0;
        int sum = 0;
        for(int i = 0; i < N; ++i){
            if(i == 0 || nums[i - 1] < nums[i]){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};