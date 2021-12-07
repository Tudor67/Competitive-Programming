class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int R = matrix.size();
        const int C = matrix[0].size();
        vector<int> answer;
        
        int minRow = 0, maxRow = R - 1;
        int minCol = 0, maxCol = C - 1;
        while(answer.size() < R * C){
            for(int col = minCol; col <= maxCol; ++col){
                answer.push_back(matrix[minRow][col]);
            }
            for(int row = minRow + 1; row <= maxRow; ++row){
                answer.push_back(matrix[row][maxCol]);
            }
            for(int col = maxCol - 1; minRow != maxRow && col >= minCol; --col){
                answer.push_back(matrix[maxRow][col]);
            }
            for(int row = maxRow - 1; minCol != maxCol && row >= minRow + 1; --row){
                answer.push_back(matrix[row][minCol]);
            }
            minRow += 1; maxRow -= 1;
            minCol += 1; maxCol -= 1;
        }
        
        return answer;
    }
};