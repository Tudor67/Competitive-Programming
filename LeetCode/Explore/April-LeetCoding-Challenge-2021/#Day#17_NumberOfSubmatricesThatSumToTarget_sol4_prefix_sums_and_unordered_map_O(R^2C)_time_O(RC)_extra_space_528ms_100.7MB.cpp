class Solution {    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> colSum = matrix;
        for(int row = 1; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                colSum[row][col] += colSum[row - 1][col];
            }
        }
        
        int answer = 0;
        unordered_map<int, int> prefSumCount;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int row2 = row1; row2 < ROWS; ++row2){
                int prefSum = 0;
                prefSumCount.clear();
                prefSumCount[0] = 1;
                for(int col = 0; col < COLS; ++col){
                    if(row1 - 1 >= 0){
                        prefSum -= colSum[row1 - 1][col];
                    }
                    prefSum += colSum[row2][col];
                    if(prefSumCount.count(prefSum - target)){
                        answer += prefSumCount[prefSum - target];
                    }
                    prefSumCount[prefSum] += 1;
                }
            }
        }
        
        return answer;
    }
};