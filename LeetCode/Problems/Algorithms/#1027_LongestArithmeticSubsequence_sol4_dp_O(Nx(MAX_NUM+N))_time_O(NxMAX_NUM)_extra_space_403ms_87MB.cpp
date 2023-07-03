class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        if(N <= 2){
            return N;
        }

        int res = 1;
        vector<vector<int>> maxLen(N, vector<int>(2 * MAX_NUM + 1, 1));

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = nums[i] - nums[j] + MAX_NUM;
                maxLen[i][diff] = max(maxLen[i][diff], maxLen[j][diff] + 1);
                res = max(res, maxLen[i][diff]);
            }
        }

        return res;
    }
};