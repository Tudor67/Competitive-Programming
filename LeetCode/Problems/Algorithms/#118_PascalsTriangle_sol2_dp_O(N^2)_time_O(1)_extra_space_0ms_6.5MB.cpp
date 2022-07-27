class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        
        for(int row = 0; row <= numRows - 1; ++row){
            a[row].resize(row + 1);
            a[row].front() = 1;
            a[row].back() = 1;
            for(int col = 1; col <= row - 1; ++col){
                a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
            }
        }
        
        return a;
    }
};