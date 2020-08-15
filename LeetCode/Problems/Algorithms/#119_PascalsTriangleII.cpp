class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> a(2, vector<int>(rowIndex + 1, 0));
        
        for(int i = 0; i <= rowIndex; ++i){
            a[i % 2][0] = 1;
            for(int j = 1; j <= i; ++j){
                a[i % 2][j] = a[(i - 1) % 2][j - 1] + a[(i - 1) % 2][j];
            }
        }
        
        return a[rowIndex % 2];
    }
};