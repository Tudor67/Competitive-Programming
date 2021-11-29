class Solution {
private:
    int solve(vector<int>& nums, int l, int r){
        if(l > r){
            return INT_MIN;
        }
        
        int mid = (l + r) / 2;
        int leftAnswer = solve(nums, l, mid - 1);
        int rightAnswer = solve(nums, mid + 1, r);
        
        int leftSum = 0;
        int leftMaxSum = 0;
        for(int i = mid - 1; i >= l; --i){
            leftSum += nums[i];
            leftMaxSum = max(leftMaxSum, leftSum);
        }
        
        int rightSum = 0;
        int rightMaxSum = 0;
        for(int i = mid + 1; i <= r; ++i){
            rightSum += nums[i];
            rightMaxSum = max(rightMaxSum, rightSum);
        }
        
        return max({leftAnswer, rightAnswer, leftMaxSum + nums[mid] + rightMaxSum});
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        return solve(nums, 0, N - 1);
    }
};