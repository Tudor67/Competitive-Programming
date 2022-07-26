class Solution {
private:
    int solve(vector<int>& nums, const int& L, const int& R, const int& THRESHOLD){
        if(L > R){
            return -1;
        }
        
        int firstIdxOfMin = min_element(nums.begin() + L, nums.begin() + R + 1) - nums.begin();
        long long minNum = nums[firstIdxOfMin];
        if(minNum * (R - L + 1) > THRESHOLD){
            return R - L + 1;
        }
        
        int leftResult = solve(nums, L, firstIdxOfMin - 1, THRESHOLD);
        int rightResult = solve(nums, firstIdxOfMin + 1, R, THRESHOLD);
        return max(leftResult, rightResult);
    }
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int N = nums.size();
        return solve(nums, 0, N - 1, threshold);
    }
};