class Solution {
public:
    int countPartitions(vector<int>& nums) {
        const int N = nums.size();

        int validPartitions = 0;
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0; i + 1 < N; ++i){
            leftSum += nums[i];
            rightSum -= nums[i];
            if((leftSum - rightSum) % 2 == 0){
                validPartitions += 1;
            }
        }

        return validPartitions;
    }
};