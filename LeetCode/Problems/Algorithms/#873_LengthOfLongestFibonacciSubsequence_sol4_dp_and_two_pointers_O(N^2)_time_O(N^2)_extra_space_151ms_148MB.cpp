class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N = arr.size();

        int maxLen = 0;
        vector<vector<int>> dp(N, vector<int>(N));

        for(int i = 0; i < N; ++i){
            int prevIndex = 0;
            for(int j = i + 1; j < N; ++j){
                int diff = arr[j] - arr[i];
                while(prevIndex < i && arr[prevIndex] < diff){
                    prevIndex += 1;
                }

                if(prevIndex < i && arr[prevIndex] == diff){
                    dp[i][j] = dp[prevIndex][i] + 1;
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