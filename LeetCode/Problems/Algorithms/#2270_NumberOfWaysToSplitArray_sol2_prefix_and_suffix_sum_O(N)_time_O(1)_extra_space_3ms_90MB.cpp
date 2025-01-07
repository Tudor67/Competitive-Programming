class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int N = nums.size();

        int validWays = 0;
        long long leftSum = 0;
        long long rightSum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i + 1 < N; ++i){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum >= rightSum){
                validWays += 1;
            }
        }

        return validWays;
    }
};