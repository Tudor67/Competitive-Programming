class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int maxArea = 0;

        vector<int> heights(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == 0){
                    heights[col] = 0;
                }else{
                    heights[col] += matrix[row][col];
                }
            }

            vector<int> sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end());

            for(int i = 0; i < COLS; ++i){
                int area = sortedHeights[i] * (COLS - i);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};