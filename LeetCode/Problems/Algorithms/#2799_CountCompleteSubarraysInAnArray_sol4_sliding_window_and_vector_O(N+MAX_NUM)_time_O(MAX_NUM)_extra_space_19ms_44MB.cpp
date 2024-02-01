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
        int l = 0;
        int windowDistinctNums = 0;
        vector<int> freq(MAX_NUM + 1);

        for(int r = 0; r < N; ++r){
            windowDistinctNums += (int)(freq[nums[r]] == 0);
            freq[nums[r]] += 1;
            if(windowDistinctNums == TOTAL_DISTINCT_NUMS){
                while(freq[nums[l]] >= 2){
                    freq[nums[l]] -= 1;
                    l += 1;
                }
                res += (l + 1);
            }
        }

        return res;
    }
};