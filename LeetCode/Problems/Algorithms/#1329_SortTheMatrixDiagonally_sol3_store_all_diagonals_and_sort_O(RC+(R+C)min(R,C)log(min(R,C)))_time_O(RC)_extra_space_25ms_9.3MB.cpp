class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        const int SHIFT = COLS - 1;
        
        vector<vector<int>> buckets(ROWS + COLS - 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                buckets[row - col + SHIFT].push_back(mat[row][col]);
            }
        }
        
        for(vector<int>& bucket: buckets){
            sort(bucket.begin(), bucket.end());
        }
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                int bucketID = row - col + SHIFT;
                res[row][col] = buckets[bucketID].back();
                buckets[bucketID].pop_back();
            }
        }
        
        return res;
    }
};