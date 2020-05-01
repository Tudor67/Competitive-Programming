class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        
        const int n = matrix.size();
        const int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i){
            dp[i][0] = matrix[i][0] - '0';
        }
        
        for(int j = 0; j < m; ++j){
            dp[0][j] = matrix[0][j] - '0';
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        
        int max_len = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                max_len = max(dp[i][j], max_len);
            }
        }
        
        return max_len * max_len;
    }
};