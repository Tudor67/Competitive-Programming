class Solution {
private:
    vector<int> originalNums;
    
public:
    Solution(vector<int>& nums) {
        originalNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return originalNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = originalNums;
        for(int i = 0; i < (int)nums.size(); ++i){
            int remSize = (int)nums.size() - i;
            int j = i + rand() % remSize;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */