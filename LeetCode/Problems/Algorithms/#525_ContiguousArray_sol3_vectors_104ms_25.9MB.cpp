class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int unvis_val = 5 * n;
        vector<int> first_pos(2 * n + 1, unvis_val);
        vector<int> last_pos(2 * n + 1, unvis_val);
        first_pos[0 + n] = -1;
        last_pos[0 + n] = -1;
        
        int bal = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                --bal;
            }else{
                ++bal;
            }
            
            if(first_pos[bal + n] == unvis_val){
                first_pos[bal + n] = i;
            }
            last_pos[bal + n] = i;
        }
        
        int ans = 0;
        for(int bal = -n; bal <= n; ++bal){
            ans = max(ans, last_pos[bal + n] - first_pos[bal + n]);
        }
        
        return ans;
    }
};