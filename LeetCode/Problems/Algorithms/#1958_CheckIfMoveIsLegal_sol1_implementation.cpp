class Solution {
private:
    bool isInsideBoard(int r, int c){
        return (0 <= r && r < 8 && 0 <= c && c < 8);
    }
    
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        const char COMPLEMENT_COLOR = (color == 'B' ? 'W' : 'B');
        
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            const int ROW_DIRECTION = DIRECTION.first;
            const int COL_DIRECTION = DIRECTION.second;
            
            int r = rMove + ROW_DIRECTION;
            int c = cMove + COL_DIRECTION;
            while(isInsideBoard(r, c) && board[r][c] == COMPLEMENT_COLOR){
                r += ROW_DIRECTION;
                c += COL_DIRECTION;
            }
            
            if(isInsideBoard(r, c) && board[r][c] == color && max(abs(r - rMove), abs(c - cMove)) + 1 >= 3){
                return true;
            }
        }
        
        return false;
    }
};