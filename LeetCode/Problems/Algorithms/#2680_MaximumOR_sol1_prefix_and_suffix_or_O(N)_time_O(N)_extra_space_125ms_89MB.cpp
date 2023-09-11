class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> prefOR(N);
        prefOR[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefOR[i] = prefOR[i - 1] | nums[i];
        }

        vector<int> suffOR(N + 1);
        for(int i = N - 1; i >= 0; --i){
            suffOR[i] = nums[i] | suffOR[i + 1];
        }

        long long maxOR = ((long long)nums[0] << k) | suffOR[1];
        for(int i = 1; i < N; ++i){
            long long currentOR = prefOR[i - 1] | ((long long)nums[i] << k) | suffOR[i + 1];
            maxOR = max(maxOR, currentOR);
        }
        
        return maxOR;
    }
};