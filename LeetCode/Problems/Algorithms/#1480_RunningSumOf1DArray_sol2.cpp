class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int N = nums.size();
        vector<int> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        return prefSum;
    }
};