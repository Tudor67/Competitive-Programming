class Solution {
private:
    int solve(vector<int>& slices, const int& K){
        const int SIZE = slices.size();
        
        // At step k:
        //    dp[k % 2][i]: max sum of at most k non-adjacent nums in slices[0 .. i]
        vector<vector<int>> dp(2, vector<int>(SIZE));
        dp[1][0] = slices[0];
        for(int i = 1; i < SIZE; ++i){
            dp[1][i] = max(dp[1][i - 1], slices[i]);
        }
        
        for(int k = 2; k <= K; ++k){
            for(int i = 0; i < SIZE; ++i){
                if(i < 2){
                    dp[k % 2][i] = dp[(k - 1) % 2][i];
                }else{
                    dp[k % 2][i] = max(dp[k % 2][i - 1], dp[(k - 1) % 2][i - 2] + slices[i]);
                }
            }
        }
        
        return dp[K % 2][SIZE - 1];
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        const int SIZE = slices.size();
        vector<int> slices1(slices.begin() + 1, slices.end());
        vector<int> slices2(slices.begin(), slices.end() - 1);
        return max(solve(slices1, SIZE / 3), solve(slices2, SIZE / 3));
    }
};