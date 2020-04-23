class Solution {
private:
    void reflect(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i){
            for(int j = 0; j < n; ++j){
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
    
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        reflect(matrix);
        transpose(matrix);
    }
};