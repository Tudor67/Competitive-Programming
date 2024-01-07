class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return 0;
        }

        vector<vector<unordered_map<long long, int>>> DP(2, vector<unordered_map<long long, int>>(N));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - (long long)nums[j];
                DP[0][i][diff] += 1;
            }
        }

        long long res = 0;
        for(int len = 3; len <= N; ++len){
            vector<unordered_map<long long, int>>& dp0 = DP[(len - 1) % 2];
            vector<unordered_map<long long, int>>& dp1 = DP[len % 2];
            
            for(int i = 0; i < N; ++i){
                dp1[i].clear();

                for(int j = 0; j < i; ++j){
                    long long diff = (long long)nums[i] - (long long)nums[j];
                    dp1[i][diff] += dp0[j][diff];
                }

                for(pair<const long long, int>& P: dp1[i]){
                    res += P.second;
                }
            }
        }

        return res;
    }
};