class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int N = arr.size();
        const int MODULO = 1e9 + 7;

        vector<int> sortedNums = arr;
        sort(sortedNums.begin(), sortedNums.end());

        int totalCount = 0;
        vector<long long> dp(N);

        for(int i = 0; i < N; ++i){
            dp[i] = 1;
            
            for(int j = 0; j < i; ++j){
                if(sortedNums[i] % sortedNums[j] == 0){
                    int k = lower_bound(sortedNums.begin(), sortedNums.begin() + i, sortedNums[i] / sortedNums[j])
                            - sortedNums.begin();
                    if(sortedNums[i] / sortedNums[j] == sortedNums[k]){
                        dp[i] += (dp[j] * dp[k]) % MODULO;
                        dp[i] %= MODULO;
                    }
                }
            }

            totalCount += dp[i];
            totalCount %= MODULO;
        }

        return totalCount;
    }
};