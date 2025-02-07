class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int N = nums.size();

        int maxSum = 0;
        int l = 0;
        while(l < N){
            int r = l;
            int sum = nums[r];
            while(r + 1 < N && nums[r] < nums[r + 1]){
                sum += nums[r + 1];
                r += 1;
            }
            maxSum = max(maxSum, sum);
            l = r + 1;
        }

        return maxSum;
    }
};