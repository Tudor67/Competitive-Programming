class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> first_pos;
        map<int, int> last_pos;
        first_pos[0] = -1;
        last_pos[0] = -1;
        
        int bal = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                --bal;
            }else{
                ++bal;
            }
            
            if(first_pos.find(bal) == first_pos.end()){
                first_pos[bal] = i;
            }
            last_pos[bal] = i;
        }
        
        
        int ans = 0;
        for(pair<int, int> p: first_pos){
            bal = p.first;
            ans = max(ans, last_pos[bal] - first_pos[bal]);
        }
        
        return ans;
    }
};