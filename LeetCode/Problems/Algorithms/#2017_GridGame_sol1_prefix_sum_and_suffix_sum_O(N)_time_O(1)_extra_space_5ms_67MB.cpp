class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int N = grid[0].size();

        long long row1SuffSum = accumulate(grid[0].begin(), grid[0].end(), (long long)0);
        long long row2PrefSum = 0;
        long long res = row1SuffSum;
        
        for(int i = 0; i < N; ++i){
            row1SuffSum -= grid[0][i];
            long long robot2Sum = max(row1SuffSum, row2PrefSum);
            res = min(res, robot2Sum);
            row2PrefSum += grid[1][i];
        }

        return res;
    }
};