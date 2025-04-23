class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);
        for(int i = N - 1; i >= 0; --i){
            if(vis[nums[i]]){
                return (i + 3) / 3;
            }
            vis[nums[i]] = true;
        }

        return 0;
    }
};