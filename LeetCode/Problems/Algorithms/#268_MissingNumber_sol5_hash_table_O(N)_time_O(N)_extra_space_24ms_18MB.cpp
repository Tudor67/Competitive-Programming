class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        
        vector<bool> vis(N + 1, false);
        for(int num: nums){
            vis[num] = true;
        }
        
        for(int i = 0; i <= N; ++i){
            if(!vis[i]){
                return i;
            }
        }
        
        return -1;
    }
};