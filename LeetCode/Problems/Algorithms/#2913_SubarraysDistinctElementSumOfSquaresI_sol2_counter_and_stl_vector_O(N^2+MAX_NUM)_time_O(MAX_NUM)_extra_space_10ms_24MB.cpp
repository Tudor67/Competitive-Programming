class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int res = 0;
        int distinctCount = 0;
        vector<bool> vis(MAX_NUM + 1, false);
        
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                distinctCount += (int)(!vis[nums[j]]);
                vis[nums[j]] = true;
                res += distinctCount * distinctCount;
            }

            distinctCount = 0;
            for(int j = i; j < N; ++j){
                vis[nums[j]] = false;
            }
        }

        return res;
    }
};