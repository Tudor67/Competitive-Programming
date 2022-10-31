class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        // Step 1: find duplicate number
        int duplicate = 0;
        vector<bool> vis(N + 1, false);
        for(int num: nums){
            if(vis[num]){
                duplicate = num;
            }
            vis[num] = true;
        }
        
        // Step 2: find missing number
        int missing = 0;
        for(int num = 1; num <= N; ++num){
            if(!vis[num]){
                missing = num;
            }
        }
        
        return {duplicate, missing};
    }
};