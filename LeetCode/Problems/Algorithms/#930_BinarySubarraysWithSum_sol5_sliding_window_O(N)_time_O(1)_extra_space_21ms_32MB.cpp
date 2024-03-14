class Solution {
private:
    int f(vector<int>& nums, int maxSum){
        const int N = nums.size();
        
        if(maxSum < 0){
            return 0;
        }

        int res = 0;
        int sum = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            sum += nums[r];
            while(sum > maxSum){
                sum -= nums[l];
                l += 1;
            }
            res += r - l + 1;
        }

        return res;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal - 1);
    }
};