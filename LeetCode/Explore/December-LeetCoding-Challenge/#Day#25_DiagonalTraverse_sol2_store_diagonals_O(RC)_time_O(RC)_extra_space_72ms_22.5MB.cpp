class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        vector<vector<int>> diag(ROWS + COLS + 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                diag[row + col].push_back(matrix[row][col]);
            }
        }
        
        vector<int> answer;
        answer.reserve(ROWS * COLS);
        for(int diagIdx = 0; diagIdx < diag.size(); ++diagIdx){
            if(diagIdx % 2 == 0){
                reverse(diag[diagIdx].begin(), diag[diagIdx].end());
            }
            for(int elem: diag[diagIdx]){
                answer.push_back(elem);
            }
        }
        
        return answer;
    }
};