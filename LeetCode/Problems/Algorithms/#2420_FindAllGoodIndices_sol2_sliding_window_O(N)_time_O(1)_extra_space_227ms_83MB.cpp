class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // Special case
        if(2 * k + 1 > N){
            return {};
        }
        
        // Sliding window
        int leftGood = 0;
        for(int i = 1; i <= k - 1; ++i){
            if(nums[i - 1] >= nums[i]){
                leftGood += 1;
            }
        }
        
        int rightGood = 0;
        for(int i = k + 1; i <= k + k - 1; ++i){
            if(nums[i] <= nums[i + 1]){
                rightGood += 1;
            }
        }
        
        vector<int> res;
        if(leftGood == k - 1 && rightGood == k - 1){
            res.push_back(k);
        }
        
        for(int i = k + 1; i + k < N; ++i){
            if(nums[i - (k + 1)] >= nums[i - k]){
                leftGood -= 1;
            }
            if(nums[i - 2] >= nums[i - 1]){
                leftGood += 1;
            }
            if(nums[i + k - 1] <= nums[i + k]){
                rightGood += 1;
            }
            if(nums[i] <= nums[i + 1]){
                rightGood -= 1;
            }
            
            if(leftGood == k - 1 && rightGood == k - 1){
                res.push_back(i);
            }
        }
        
        return res;
    }
};