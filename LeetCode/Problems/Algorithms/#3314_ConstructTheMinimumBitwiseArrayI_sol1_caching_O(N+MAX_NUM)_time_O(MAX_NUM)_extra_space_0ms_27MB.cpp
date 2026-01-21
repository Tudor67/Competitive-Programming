class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> minAnsFor(MAX_NUM + 1, -1);
        for(int x = 0; x <= MAX_NUM; ++x){
            int orVal = x | (x + 1);
            if(orVal <= MAX_NUM && minAnsFor[orVal] == -1){
                minAnsFor[orVal] = x;
            }
        }

        vector<int> ans(N);
        for(int i = 0; i < N; ++i){
            ans[i] = minAnsFor[nums[i]];
        }

        return ans;
    }
};