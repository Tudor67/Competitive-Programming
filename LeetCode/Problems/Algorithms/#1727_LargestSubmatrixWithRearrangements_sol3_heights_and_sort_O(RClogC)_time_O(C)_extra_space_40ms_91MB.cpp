class Solution {
private:
    int computeMaxArea(vector<int> heights){
        const int N = heights.size();

        sort(heights.begin(), heights.end(), greater<>());

        int maxArea = 0;
        for(int i = 0; i < N; ++i){
            if(i + 1 == N || heights[i] != heights[i + 1]){
                maxArea = max(maxArea, heights[i] * (i + 1));
            }
        }

        return maxArea;
    }

public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(COLS);
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == 1){
                    heights[col] += 1;
                }else{
                    heights[col] = 0;
                }
            }
            maxArea = max(maxArea, computeMaxArea(heights));
        }

        return maxArea;
    }
};