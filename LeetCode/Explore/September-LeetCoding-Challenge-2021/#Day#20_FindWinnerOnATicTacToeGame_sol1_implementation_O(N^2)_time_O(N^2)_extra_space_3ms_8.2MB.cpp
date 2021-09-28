class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3, -1));
        for(int i = 0; i < (int)moves.size(); ++i){
            board[moves[i][0]][moves[i][1]] = i % 2;
        }
        
        if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != -1) ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != -1)){
            return string(1, 'A' + board[1][1]);
        }
        
        for(int row = 0; row < 3; ++row){
            int count0 = 0;
            int count1 = 0;
            for(int col = 0; col < 3; ++col){
                count0 += (board[row][col] == 0);
                count1 += (board[row][col] == 1);
            }
            if(count0 == 3){
                return "A";
            }
            if(count1 == 3){
                return "B";
            }
        }

        for(int col = 0; col < 3; ++col){
            int count0 = 0;
            int count1 = 0;
            for(int row = 0; row < 3; ++row){
                count0 += (board[row][col] == 0);
                count1 += (board[row][col] == 1);
            }
            if(count0 == 3){
                return "A";
            }
            if(count1 == 3){
                return "B";
            }
        }
        
        int emptyCellsCount = 0;
        for(int row = 0; row < 3; ++row){
            for(int col = 0; col < 3; ++col){
                emptyCellsCount += (board[row][col] == -1);
            }
        }
        if(emptyCellsCount > 0){
            return "Pending";
        }
        
        return "Draw";
    }
};