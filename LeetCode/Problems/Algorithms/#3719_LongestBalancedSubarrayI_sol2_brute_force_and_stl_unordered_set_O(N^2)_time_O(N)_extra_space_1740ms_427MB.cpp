class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        vector<unordered_set<int>> vis(2);

        for(int i = 0; i < N; ++i){
            vis[0].clear();
            vis[1].clear();
            for(int j = i; j < N; ++j){
                vis[nums[j] % 2].insert(nums[j]);
                if(vis[0].size() == vis[1].size()){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};