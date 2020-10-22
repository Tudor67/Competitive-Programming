class Solution {
public:
    void rotate(vector<int>& nums, int K) {
        const int N = nums.size();
        K %= N;
        
        if(K == 0){
            return;
        }
        
        // Step 1: reverse nums
        reverse(nums.begin(), nums.end());
        
        // Step 2: correct nums in range [0, K - 1]
        reverse(nums.begin(), nums.begin() + K);
        
        // Step 3: correct nums in range [K, N - 1]
        reverse(nums.begin() + K, nums.end());
    }
};