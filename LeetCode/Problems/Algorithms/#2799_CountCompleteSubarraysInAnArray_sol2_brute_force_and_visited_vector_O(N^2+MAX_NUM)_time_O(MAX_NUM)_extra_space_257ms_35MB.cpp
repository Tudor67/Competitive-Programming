class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1, false);
        for(int num: nums){
            vis[num] = true;
        }

        const int TOTAL_DISTINCT_NUMS = count(vis.begin(), vis.end(), true);

        int res = 0;
        int subarrayDistinctNums = 0;
        fill(vis.begin(), vis.end(), false);

        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                subarrayDistinctNums += (!vis[nums[j]]);
                vis[nums[j]] = true;
                if(subarrayDistinctNums == TOTAL_DISTINCT_NUMS){
                    res += 1;
                }
            }

            for(int j = i; j < N; ++j){
                subarrayDistinctNums -= vis[nums[j]];
                vis[nums[j]] = false;
            }
        }

        return res;
    }
};