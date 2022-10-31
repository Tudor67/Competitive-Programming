class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        // Step 1: find duplicate number
        int duplicate = 0;
        for(int num: nums){
            int val = abs(num);
            int pos = val - 1;
            bool isVisited = (nums[pos] < 0);
            if(isVisited){
                duplicate = val;
            }
            nums[pos] = -nums[pos];
        }
        
        // Step 2: find missing number
        int missing = 0;
        for(int num = 1; num <= N; ++num){
            if(nums[num - 1] > 0 && num != duplicate){
                missing = num;
            }
        }
        
        // Step 3: restore the initial values of nums vector
        for(int& num: nums){
            if(num < 0){
                num = -num;
            }
        }
        
        return {duplicate, missing};
    }
};