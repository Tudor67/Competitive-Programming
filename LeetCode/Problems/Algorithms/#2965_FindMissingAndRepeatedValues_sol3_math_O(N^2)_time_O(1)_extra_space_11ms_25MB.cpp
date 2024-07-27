class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const long long N = grid.size();
        const long long SIZE = N * N;

        long long sum = 0;
        long long sumOfSquares = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                sum += grid[row][col];
                sumOfSquares += grid[row][col] * grid[row][col];
            }
        }

        long long abDiff = sum - SIZE * (SIZE + 1) / 2;
        long long abSum = (sumOfSquares - SIZE * (SIZE + 1) * (2 * SIZE + 1) / 6) / abDiff;

        int a = (abSum + abDiff) / 2;
        int b = (abSum - abDiff) / 2;

        return {a, b};
    }
};