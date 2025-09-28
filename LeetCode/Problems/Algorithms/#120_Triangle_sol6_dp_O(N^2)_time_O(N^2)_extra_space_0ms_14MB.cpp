class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = triangle.size();
        const int INF = 1e9;

        vector<vector<int>> minSum(N, vector<int>(N, INF));
        minSum[0][0] = triangle[0][0];

        for(int row = 1; row < N; ++row){
            minSum[row][0] = triangle[row][0] + minSum[row - 1][0];
            for(int col = 1; col <= row; ++col){
                minSum[row][col] = triangle[row][col] + min(minSum[row - 1][col - 1],
                                                            minSum[row - 1][col]);
            }
        }

        return *min_element(minSum[N - 1].begin(), minSum[N - 1].end());
    }
};