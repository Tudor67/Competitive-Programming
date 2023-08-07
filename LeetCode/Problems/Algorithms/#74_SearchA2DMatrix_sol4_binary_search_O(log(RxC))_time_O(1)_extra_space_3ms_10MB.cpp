class Solution {
private:
    int getRow(int index, const int COLS){
        return index / COLS;
    }

    int getCol(int index, const int COLS){
        return index % COLS;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int l = 0;
        int r = ROWS * COLS - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(matrix[getRow(mid, COLS)][getCol(mid, COLS)] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return (matrix[getRow(r, COLS)][getCol(r, COLS)] == target);
    }
};