class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> res(N);

        int uniqueNums = 0;
        vector<bool> vis(MAX_NUM + 1, false);
        for(int i = 0; i < N; ++i){
            uniqueNums += (int)(!vis[nums[i]]);
            vis[nums[i]] = true;
            res[i] += uniqueNums;
        }

        uniqueNums = 0;
        fill(vis.begin(), vis.end(), false);
        for(int i = N - 1; i >= 0; --i){
            res[i] -= uniqueNums;
            uniqueNums += (int)(!vis[nums[i]]);
            vis[nums[i]] = true;
        }
        
        return res;
    }
};