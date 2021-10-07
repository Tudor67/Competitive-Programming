class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<int> colXOR(COLS, 0);
        vector<int> xorValues;
        for(int row = 0; row < ROWS; ++row){
            int prefXOR = 0;
            for(int col = 0; col < COLS; ++col){
                colXOR[col] ^= matrix[row][col];
                prefXOR ^= colXOR[col];
                xorValues.push_back(prefXOR);
            }
        }
        
        sort(xorValues.rbegin(), xorValues.rend());
        
        return xorValues[k - 1];
    }
};