class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        const int M = moves.size();
        const int N = 3;
        const int P = 2;
        
        vector<vector<int>> rowCount(N, vector<int>(P + 1, 0));
        vector<vector<int>> colCount(N, vector<int>(P + 1, 0));
        vector<int> mainDiagCount(P + 1, 0);
        vector<int> secondDiagCount(P + 1, 0);
        for(int i = 0; i < M; ++i){
            int row = moves[i][0];
            int col = moves[i][1];
            int player = 1 + (i % 2);
            rowCount[row][player] += 1;
            colCount[col][player] += 1;
            if(row == col){
                mainDiagCount[player] += 1;
            }
            if(row + col == N - 1){
                secondDiagCount[player] += 1;
            }
        }
        
        for(int row = 0; row < N; ++row){
            for(int player = 1; player <= P; ++player){
                if(rowCount[row][player] == N){
                    return string(1, 'A' + player - 1);
                }
            }
        }
        
        for(int col = 0; col < N; ++col){
            for(int player = 1; player <= P; ++player){
                if(colCount[col][player] == N){
                    return string(1, 'A' + player - 1);
                }
            }
        }
        
        for(int player = 1; player <= P; ++player){
            if(mainDiagCount[player] == N || secondDiagCount[player] == N){
                return string(1, 'A' + player - 1);
            }
        }
        
        int emptyCellsCount = N * N - M;
        if(emptyCellsCount >= 1){
            return "Pending";
        }
        
        return "Draw";
    }
};