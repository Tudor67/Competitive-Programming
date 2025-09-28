class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = triangle.size();
        const int INF = 1e9;

        vector<vector<int>> minSum(2, vector<int>(N, INF));
        minSum[0][0] = triangle[0][0];

        for(int row = 1; row < N; ++row){
            minSum[row % 2][0] = triangle[row][0] + minSum[(row - 1) % 2][0];
            for(int col = 1; col <= row; ++col){
                minSum[row % 2][col] = triangle[row][col] + min(minSum[(row - 1) % 2][col - 1],
                                                                minSum[(row - 1) % 2][col]);
            }
        }

        return *min_element(minSum[(N - 1) % 2].begin(), minSum[(N - 1) % 2].end());
    }
};