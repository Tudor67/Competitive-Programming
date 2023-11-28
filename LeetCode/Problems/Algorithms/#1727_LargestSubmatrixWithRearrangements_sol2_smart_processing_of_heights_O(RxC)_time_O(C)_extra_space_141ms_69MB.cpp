class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int maxArea = 0;

        vector<pair<int, int>> prevHC;
        vector<pair<int, int>> hc;
        vector<bool> included(COLS);

        for(int row = 0; row < ROWS; ++row){
            prevHC = hc;
            hc.clear();
            fill(included.begin(), included.end(), false);

            for(pair<int, int>& P: prevHC){
                int prevHeight = P.first;
                int prevCol = P.second;
                if(matrix[row][prevCol] == 1){
                    hc.push_back({prevHeight + 1, prevCol});
                    included[prevCol] = true;
                }
            }

            for(int col = 0; col < COLS; ++col){
                if(!included[col] && matrix[row][col] == 1){
                    hc.push_back({1, col});
                }
            }

            int width = 0;
            for(pair<int, int>& P: hc){
                int height = P.first;
                width += 1;
                int area = width * height;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};