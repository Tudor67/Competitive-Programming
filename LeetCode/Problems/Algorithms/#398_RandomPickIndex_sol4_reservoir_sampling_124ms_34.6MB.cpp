class Solution {
private:
    const vector<int>& NUMS;
    
public:
    Solution(vector<int>& nums): NUMS(nums) {}
    
    int pick(int target) {
        int idx = -1;
        int cnt = 0;
        for(int i = 0; i < NUMS.size(); ++i){
            if(NUMS[i] == target){
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