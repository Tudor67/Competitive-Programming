class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        vector<vector<int>> prefSum = matrix;
        for(int i = 1; i < N; ++i){
            prefSum[i][0] += prefSum[i - 1][0];
        }
        
        for(int j = 1; j < M; ++j){
            prefSum[0][j] += prefSum[0][j - 1];
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < M; ++j){
                prefSum[i][j] += prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
            }
        }
        
        int answer = 0;
        for(int i2 = 0; i2 < N; ++i2){
            for(int j2 = 0; j2 < M; ++j2){
                for(int i1 = 0; i1 <= i2; ++i1){
                    for(int j1 = 0; j1 <= j2; ++j1){
                        int s = prefSum[i2][j2];
                        if(i1 - 1 >= 0){
                            s -= prefSum[i1 - 1][j2];
                        }
                        if(j1 - 1 >= 0){
                            s -= prefSum[i2][j1 - 1];
                        }
                        if(i1 - 1 >= 0 && j1 - 1 >= 0){
                            s += prefSum[i1 - 1][j1 - 1];
                        }
                        answer += (s == target);
                    }
                }
            }
        }
        
        return answer;
    }
};