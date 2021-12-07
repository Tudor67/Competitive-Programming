class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        vector<int> avgs(N, -1);
        for(int i = k; i + k < N; ++i){
            long long leftSum = 0;
            if(i - 1 >= 0){
                leftSum = prefSum[i - 1];
            }
            if(i - k - 1 >= 0){
                leftSum -= prefSum[i - k - 1];
            }
            long long rightSum = prefSum[i + k] - prefSum[i];
            avgs[i] = (leftSum + nums[i] + rightSum) / (2 * k + 1);
        }
        
        return avgs;
    }
};