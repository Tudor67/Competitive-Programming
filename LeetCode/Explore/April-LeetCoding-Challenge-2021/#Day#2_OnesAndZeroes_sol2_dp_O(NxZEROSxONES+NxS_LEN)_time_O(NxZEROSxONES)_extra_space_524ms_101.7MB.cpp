class Solution {
public:
    int findMaxForm(vector<string>& strs, int ZEROS, int ONES) {
        const int N = strs.size();
        int answer = 0;
        
        vector<int> zerosAt(N);
        vector<int> onesAt(N);
        for(int i = 0; i < N; ++i){
            zerosAt[i] = count(strs[i].begin(), strs[i].end(), '0');
            onesAt[i] = count(strs[i].begin(), strs[i].end(), '1');
        }
        
        // dp[i][zeros][ones]: max size of a subset when:
        //                     included strings are from strs[0..i],
        //                     the total number of zeros is `zeros` and
        //                     the total number of ones is `ones`
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(ZEROS + 1, vector<int>(ONES + 1, 0)));
        if(zerosAt[0] <= ZEROS && onesAt[0] <= ONES){
            dp[0][zerosAt[0]][onesAt[0]] = 1;
            answer = 1;
        }
        for(int i = 1; i < N; ++i){
            dp[i] = dp[i - 1];
            for(int zeros = ZEROS; zeros >= zerosAt[i]; --zeros){
                for(int ones = ONES; ones >= onesAt[i]; --ones){
                    dp[i][zeros][ones] = max(dp[i - 1][zeros - zerosAt[i]][ones - onesAt[i]] + 1, dp[i][zeros][ones]);
                    answer = max(dp[i][zeros][ones], answer);
                }
            }
        }
        
        return answer;
    }
};