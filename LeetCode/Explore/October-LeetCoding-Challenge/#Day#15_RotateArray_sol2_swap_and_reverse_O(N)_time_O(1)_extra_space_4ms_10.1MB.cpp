class Solution {
public:
    void rotate(vector<int>& nums, int K) {
        const int N = nums.size();
        K %= N;
        
        if(K == 0){
            return;
        }
        
        // Step 1: correct nums in range [0, K - 1]
        for(int i = 0, j = N - 1; max(i, N - K) <= j; ++i, --j){
            swap(nums[i], nums[j]);
        }
        
        for(int i = 0, j = K - 1; i < j; ++i, --j){
            swap(nums[i], nums[j]);
        }
        
        // Step 2: correct nums in range [K, 2K - 1]
        for(int i = K, j = N - 1; i < j; ++i, --j){
            swap(nums[i], nums[j]);
        }
        
        // Step 3: correct nums in range [2K, N - 1]
        for(int i = 2 * K, j = N - 1; i < j; ++i, --j){
            swap(nums[i], nums[j]);
        }
    }
};