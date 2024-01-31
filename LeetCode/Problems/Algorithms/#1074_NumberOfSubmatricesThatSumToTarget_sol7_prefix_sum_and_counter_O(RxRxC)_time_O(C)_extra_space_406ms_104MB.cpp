class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int res = 0;
        vector<int> sumAt(COLS);
        unordered_map<int, int> f;

        for(int row1 = 0; row1 < ROWS; ++row1){
            fill(sumAt.begin(), sumAt.end(), 0);
            for(int row2 = row1; row2 < ROWS; ++row2){
                f.clear();
                f[0] = 1;
                int prefSum = 0;
                for(int col = 0; col < COLS; ++col){
                    sumAt[col] += matrix[row2][col];
                    prefSum += sumAt[col];
                    if(f.count(prefSum - target)){
                        res += f[prefSum - target];
                    }
                    f[prefSum] += 1;
                }
            }
        }

        return res;
    }
};