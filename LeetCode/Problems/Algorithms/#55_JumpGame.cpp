class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        
        int max_pos = nums[0];
        for(int i = 0; i <= max_pos && i < n; ++i){
            max_pos = max(i + nums[i], max_pos);
        }
        
        return (max_pos >= n - 1);
    }
};