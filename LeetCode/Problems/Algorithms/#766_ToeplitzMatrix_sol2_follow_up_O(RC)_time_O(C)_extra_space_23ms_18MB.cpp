class Solution {
private:
    int readElemFromFile(vector<vector<int>>& matrix, int elemIndex){
        const int COLS = matrix[0].size();
        return matrix[elemIndex / COLS][elemIndex % COLS];
    }
    
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        deque<int> rowBuffer;
        for(int elemIndex = 0; elemIndex < COLS; ++elemIndex){
            rowBuffer.push_back(readElemFromFile(matrix, elemIndex));
        }
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                int elemIndex = row * COLS + col;
                if(rowBuffer[col - 1] != readElemFromFile(matrix, elemIndex)){
                    return false;
                }
            }
            rowBuffer.pop_back();
            rowBuffer.push_front(readElemFromFile(matrix, row * COLS));
        }
        
        return true;
    }
};