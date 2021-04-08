class Solution {
public:
    int findMaxForm(vector<string>& strs, int ZEROS, int ONES) {
        const int N = strs.size();
        
        vector<int> zerosAt(N);
        vector<int> onesAt(N);
        for(int i = 0; i < N; ++i){
            zerosAt[i] = count(strs[i].begin(), strs[i].end(), '0');
            onesAt[i] = count(strs[i].begin(), strs[i].end(), '1');
        }
        
        // dp[i][zeros][ones]: max size of a subset when:
        //                     the last included string is strs[i],
        //                     the total number of zeros is `zeros` and
        //                     the total number of ones is `ones`
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(ZEROS + 1, vector<int>(ONES + 1, 0)));
        for(int i = 0; i < N; ++i){
            if(zerosAt[i] <= ZEROS && onesAt[i] <= ONES){
                dp[i][zerosAt[i]][onesAt[i]] = 1;
                for(int j = 0; j < i; ++j){
                    for(int zeros = ZEROS; zeros >= zerosAt[i]; --zeros){
                        for(int ones = ONES; ones >= onesAt[i]; --ones){
                            dp[i][zeros][ones] = max(dp[j][zeros - zerosAt[i]][ones - onesAt[i]] + 1, dp[i][zeros][ones]);
                        }
                    }
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            for(int zeros = 0; zeros <= ZEROS; ++zeros){
                for(int ones = 0; ones <= ONES; ++ones){
                    answer = max(dp[i][zeros][ones], answer);
                }
            }
        }
        
        return answer;
    }
};