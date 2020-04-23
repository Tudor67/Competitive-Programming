class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        
        for(int i = n - 2; i >= 0; --i){
            output[i] = nums[i + 1] * output[i + 1];
        }
        
        int prefix = 1;
        for(int i = 0; i <= n - 1; ++i){
            output[i] *= prefix;
            prefix *= nums[i];
        }
        
        return output;
    }
};