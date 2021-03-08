class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        int duplicate = -1;
        int missing = -1;
        
        vector<bool> vis(N + 1, false);
        for(int num: nums){
            if(vis[num]){
                duplicate = num;
            }
            vis[num] = true;
        }
        
        for(int num = 1; num <= N; ++num){
            if(!vis[num]){
                missing = num;
            }
        }
        
        return {duplicate, missing};
    }
};