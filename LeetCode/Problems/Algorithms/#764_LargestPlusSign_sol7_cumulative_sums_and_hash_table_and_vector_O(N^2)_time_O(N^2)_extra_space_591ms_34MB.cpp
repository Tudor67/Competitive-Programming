class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        unordered_set<int> minesSet;
        for(const vector<int>& P: mines){
            minesSet.insert((P[0] + 1) * (N + 2) + P[1] + 1);
        }
        
        // dp[row][col]: min of (max count of consecutive ones that start at (row, col)
        //                       and move to the left until meeting the first zero,
        //                       max count of consecutive ones that start at (row, col)
        //                       and move to the right until meeting the first zero)
        // dp[row][col]: 0 if mines.count({row, col})
        vector<vector<int>> dp(N + 2, vector<int>(N + 2));
        for(int row = 1; row <= N; ++row){
            int count = 0;
            for(int col = 1; col <= N; ++col){
                if(minesSet.count(row * (N + 2) + col)){
                    count = 0;
                }else{
                    count += 1;
                }
                dp[row][col] = count;
            }
            
            count = 0;
            for(int col = N; col >= 1; --col){
                if(minesSet.count(row * (N + 2) + col)){
                    count = 0;
                }else{
                    count += 1;
                }
                dp[row][col] = min(dp[row][col], count);
            }
        }
        
        // dp[row][col]: min of (max count of consecutive ones that start at (row, col)
        //                       and move to the left until meeting the first zero,
        //                       max count of consecutive ones that start at (row, col)
        //                       and move to the right until meeting the first zero,
        //                       max count of consecutive ones that start at (row, col)
        //                       and move up until meeting the first zero,
        //                       max count of consecutive ones that start at (row, col)
        //                       and move down until meeting the first zero)
        // dp[row][col]: 0 if mines.count({row, col})
        int maxK = 0;
        for(int col = 1; col <= N; ++col){
            int count = 0;
            for(int row = 1; row <= N; ++row){
                if(minesSet.count(row * (N + 2) + col)){
                    count = 0;
                }else{
                    count += 1;
                }
                dp[row][col] = min(dp[row][col], count);
            }
            
            count = 0;
            for(int row = N; row >= 1; --row){
                if(minesSet.count(row * (N + 2) + col)){
                    count = 0;
                }else{
                    count += 1;
                }
                dp[row][col] = min(dp[row][col], count);
                maxK = max(maxK, dp[row][col]);
            }
        }
        
        return maxK;
    }
};