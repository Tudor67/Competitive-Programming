class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();

        long long currSum = 0;
        long long currSumOfSquares = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                currSum += grid[row][col];
                currSumOfSquares += (grid[row][col] * grid[row][col]);
            }
        }

        long long size = N * N;
        long long targetSum = size * (size + 1) / 2;
        long long targetSumOfSquares = size * (size + 1) * (2 * size + 1) / 6;

        long long missingDuplicateDiff = targetSum - currSum;
        long long missingDuplicateDiffOfSquares = targetSumOfSquares - currSumOfSquares;
        long long missingDuplicateSum = missingDuplicateDiffOfSquares / missingDuplicateDiff;

        return {(int)(missingDuplicateSum - missingDuplicateDiff) / 2,
                (int)(missingDuplicateDiff + missingDuplicateSum) / 2};
    }
};