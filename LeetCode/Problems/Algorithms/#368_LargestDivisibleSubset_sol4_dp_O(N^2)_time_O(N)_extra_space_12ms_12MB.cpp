class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // dp[i]: max size of a valid subset of sortedNums[0 .. i]
        //        when sortedNums[i] is included in the subset
        // prev[i]: index of the previous element included in the max valid subset
        vector<int> dp(N, 1);
        vector<int> prev(N, -1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(sortedNums[i] % sortedNums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        int i = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> res;
        res.reserve(dp[i]);
        while(i != -1){
            res.push_back(sortedNums[i]);
            i = prev[i];
        }

        return res;
    }
};