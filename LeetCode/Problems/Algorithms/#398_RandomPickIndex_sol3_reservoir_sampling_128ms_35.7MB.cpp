class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int idx = -1;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == target){
                cnt += 1;
                if(1 + rand() % cnt == cnt){
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */