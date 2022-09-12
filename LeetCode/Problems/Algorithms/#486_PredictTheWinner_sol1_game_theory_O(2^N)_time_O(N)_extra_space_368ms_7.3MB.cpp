class Solution {
private:
    int solve(int leftIdx, int rightIdx, vector<int>& nums){
        if(leftIdx == rightIdx){
            return nums[rightIdx];
        }
        int diff1 = nums[leftIdx] - solve(leftIdx + 1, rightIdx, nums);
        int diff2 = nums[rightIdx] - solve(leftIdx, rightIdx - 1, nums);
        return max(diff1, diff2);
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        return (solve(0, N - 1, nums) >= 0);
    }
};