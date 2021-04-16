class Solution {
private:
    inline int valAt(vector<vector<int>>& matrix, int row, int col){
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        if(0 <= row && row < ROWS && 0 <= col && col < COLS){
            return matrix[row][col];
        }
        return 0;
    }
    
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        // prefSum[row][col] = matrix[0][0] + matrix[0][1] + ... + matrix[0][col] +
        //                     matrix[1][0] + matrix[1][1] + ... + matrix[1][col] +
        //                     matrix[2][0] + matrix[2][1] + ... + matrix[2][col] +
        //                     ...
        //                     matrix[row][0] + matrix[row][1] + ... + matrix[row][col]
        vector<vector<int>> prefSum = matrix;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                prefSum[row][col] += prefSum[row][col - 1];
            }
        }
        
        for(int col = 0; col < COLS; ++col){
            for(int row = 1; row < ROWS; ++row){
                prefSum[row][col] += prefSum[row - 1][col];
            }
        }
        
        // colDiffs[col1][col2]: set of pairs{
        //      {prefSum[0][col2] - prefSum[0][col1 - 1], 0},
        //      {prefSum[1][col2] - prefSum[1][col1 - 1], 1},
        //       ...
        //      {prefSum[ROWS - 1][col2] - prefSum[ROWS - 1][col1 - 1], ROWS - 1}
        // }
        vector<vector<set<pair<int, int>>>> colDiffs(COLS, vector<set<pair<int, int>>>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = col1; col2 < COLS; ++col2){
                    colDiffs[col1][col2].emplace(prefSum[row][col2] - valAt(prefSum, row, col1 - 1), row);
                }
            }
        }
        
        int answer = INT_MIN;
        for(int row = 0; row < ROWS; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = col1; col2 < COLS; ++col2){
                    int prevSum = valAt(prefSum, row - 1, col2) - valAt(prefSum, row - 1, col1 - 1);
                    auto it = colDiffs[col1][col2].lower_bound({prevSum + k, row});
                    vector<int> candidates;
                    if(it != colDiffs[col1][col2].end()){
                        candidates.push_back(it->first - prevSum);
                    }
                    if(it != colDiffs[col1][col2].begin()){
                        candidates.push_back(prev(it)->first - prevSum);
                    }
                    for(int candidate: candidates){
                        if(candidate <= k){
                            answer = max(candidate, answer);
                        }
                    }
                    colDiffs[col1][col2].erase({prefSum[row][col2] - valAt(prefSum, row, col1 - 1), row});
                }
            }
        }
        
        return answer;
    }
};