class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int N = nums.size();
        
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        vector<long long> suffSum(N);
        suffSum[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = nums[i] + suffSum[i + 1];
        }
        
        vector<long long> diffs(N);
        diffs[N - 1] = abs(prefSum[N - 1] / N);
        for(int i = 0; i + 1 < N; ++i){
            diffs[i] = abs(prefSum[i] / (i + 1) - suffSum[i + 1] / (N - 1 - i));
        }
        
        return min_element(diffs.begin(), diffs.end()) - diffs.begin();
    }
};