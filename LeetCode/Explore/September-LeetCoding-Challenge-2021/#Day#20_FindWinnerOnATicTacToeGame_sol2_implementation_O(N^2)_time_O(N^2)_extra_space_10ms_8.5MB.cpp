class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        const int M = moves.size();
        const int N = 3;
        
        vector<vector<int>> board(N, vector<int>(N, 0));
        vector<vector<int>> rowCount(N, vector<int>(3, 0));
        vector<vector<int>> colCount(N, vector<int>(3, 0));
        for(int i = 0; i < M; ++i){
            int row = moves[i][0];
            int col = moves[i][1];
            int player = 1 + (i % 2);
            board[row][col] = player;
            rowCount[row][player] += 1;
            colCount[col][player] += 1;
        }
        
        for(int row = 0; row < N; ++row){
            for(int player = 1; player <= 2; ++player){
                if(rowCount[row][player] == N){
                    return string(1, 'A' + player - 1);
                }
            }
        }
        
        for(int col = 0; col < N; ++col){
            for(int player = 1; player <= 2; ++player){
                if(colCount[col][player] == N){
                    return string(1, 'A' + player - 1);
                }
            }
        }
        
        if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] >= 1) ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] >= 1)){
            return string(1, 'A' + board[1][1] - 1);
        }
        
        int emptyCellsCount = N * N - M;
        if(emptyCellsCount >= 1){
            return "Pending";
        }
        
        return "Draw";
    }
};