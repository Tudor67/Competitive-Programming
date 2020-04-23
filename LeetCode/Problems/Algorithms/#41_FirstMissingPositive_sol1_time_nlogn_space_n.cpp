class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool> vis;
        for(int x: nums){
            vis[x] = 1;
        }
        
        int ans = -1;
        for(int x = 1; x <= nums.size() + 1; ++x){
            if(vis.count(x) == 0){
                ans = x;
                break;
            }
        }
        
        return ans;
    }
};