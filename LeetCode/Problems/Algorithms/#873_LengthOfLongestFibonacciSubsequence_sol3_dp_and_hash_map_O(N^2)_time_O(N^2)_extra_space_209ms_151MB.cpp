class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N = arr.size();

        unordered_map<int, int> numToIndex;
        for(int i = 0; i < N; ++i){
            numToIndex[arr[i]] = i;
        }

        int maxLen = 0;
        vector<vector<int>> dp(N, vector<int>(N));
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int diff = arr[j] - arr[i];
                if(diff < arr[i] && numToIndex.count(diff)){
                    dp[i][j] = dp[numToIndex[diff]][i] + 1;
                }else{
                    dp[i][j] = 2;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        if(maxLen <= 2){
            maxLen = 0;
        }

        return maxLen;
    }
};