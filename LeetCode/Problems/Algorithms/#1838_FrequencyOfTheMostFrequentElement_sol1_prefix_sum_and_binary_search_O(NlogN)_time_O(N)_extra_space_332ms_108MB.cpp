class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        int maxFreq = 0;
        for(int i = 0; i < N; ++i){
            // binary search max len such that nums[i - len + 1 .. i]
            // can be converted (using at most k operations)
            // to the constant sequence with all elements equal to nums[i]
            int l = 1;
            int r = i + 1;
            while(l != r){
                long long mid = (l + r + 1) / 2;
                long long currentSum = prefSum[i] - (i - mid >= 0 ? prefSum[i - mid] : 0);
                long long targetSum = mid * nums[i];
                long long need = targetSum - currentSum;
                if(need <= k){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            maxFreq = max(maxFreq, r);
        }
        
        return maxFreq;
    }
};