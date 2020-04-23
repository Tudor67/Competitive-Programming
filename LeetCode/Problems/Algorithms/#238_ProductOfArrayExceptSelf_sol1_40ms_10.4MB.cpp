class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n + 1, 1);
        vector<int> output(n);
        
        for(int i = n - 1; i > 0; --i){
            suffix[i] = nums[i] * suffix[i + 1];
        }
        
        int prefix = 1;
        for(int i = 0; i <= n - 1; ++i){
            output[i] = prefix * suffix[i + 1];
            prefix *= nums[i];
        }
        
        return output;
    }
};