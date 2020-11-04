class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        int sum = 0;
        vector<int> cols;
        for(int row = 0; row < ROWS; ++row){
            sum += mat[row][0];
            cols.push_back(0);
        }
        
        set<pair<int, vector<int>>> sumCols;
        sumCols.insert({sum, cols});
        
        for(k = k - 1; k >= 1; --k){
            sum = sumCols.begin()->first;
            cols = sumCols.begin()->second;
            sumCols.erase(sumCols.begin());
            
            for(int row = 0; row < ROWS; ++row){
                if(cols[row] + 1 < COLS){
                    cols[row] += 1;
                    sumCols.insert({sum - mat[row][cols[row] - 1] + mat[row][cols[row]], cols});
                    cols[row] -= 1;
                }
            }
        }
        
        return sumCols.begin()->first;
    }
};