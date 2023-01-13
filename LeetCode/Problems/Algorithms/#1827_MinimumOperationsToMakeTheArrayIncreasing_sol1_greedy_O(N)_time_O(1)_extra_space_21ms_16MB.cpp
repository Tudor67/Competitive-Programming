class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        int prevNum = nums[0];
        for(int i = 1; i < N; ++i){
            int currentNum = max(prevNum + 1, nums[i]);
            res += (currentNum - nums[i]);
            prevNum = currentNum;
        }

        return res;
    }
};