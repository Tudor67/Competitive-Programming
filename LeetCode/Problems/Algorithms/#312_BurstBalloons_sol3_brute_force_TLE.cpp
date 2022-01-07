class Solution {
private:
    int solve(vector<int>& nums){
        const int N = nums.size();
        
        int maxVal = 0;
        for(int i = 0; i < N; ++i){
            int val = nums[i];
            if(i - 1 >= 0){
                val *= nums[i - 1];
            }
            if(i + 1 < N){
                val *= nums[i + 1];
            }
            
            int tempNum = nums[i];
            for(int j = i; j + 1 < N; ++j){
                nums[j] = nums[j + 1];
            }
            nums.resize(N - 1);
            
            maxVal = max(maxVal, val + solve(nums));
            
            nums.resize(N);
            for(int j = N - 1; j >= i + 1; --j){
                nums[j] = nums[j - 1];
            }
            nums[i] = tempNum;
        }
        
        return maxVal;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        return solve(nums);
    }
};