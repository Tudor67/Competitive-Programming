class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> line_vis_elem;
    vector<vector<bool>> col_vis_elem;
    vector<vector<bool>> sub_box_vis_elem;
    vector<short int> next_pos; 
    
    void back(short int cur_pos, short int vis_cnt, bool& is_solved){
        if(vis_cnt == 9 * 9){
            is_solved = 1;
        }else{
            short int i = cur_pos / 9;
            short int j = cur_pos % 9;
            short int sub_box_idx = 3 * (i / 3) + j / 3;
            for(short int digit = 1; !is_solved && digit <= 9; ++digit){
                if(!line_vis_elem[i][digit] && !col_vis_elem[j][digit] && !sub_box_vis_elem[sub_box_idx][digit]){
                    board[i][j] = char(digit + '0');
                    line_vis_elem[i][digit] = 1;
                    col_vis_elem[j][digit] = 1;
                    sub_box_vis_elem[sub_box_idx][digit] = 1;
                    
                    back(next_pos[cur_pos], vis_cnt + 1, is_solved);
                    
                    line_vis_elem[i][digit] = 0;
                    col_vis_elem[j][digit] = 0;
                    sub_box_vis_elem[sub_box_idx][digit] = 0;
                }
            }
        }
    }
    
public:
    Solution(){
        line_vis_elem.resize(9, vector<bool>(10));
        col_vis_elem.resize(9, vector<bool>(10));
        sub_box_vis_elem.resize(9, vector<bool>(10));
        next_pos.resize(9 * 9);
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // board initialization
        this->board = board;
        
        // mark visited digits along the lines, columns and sub-boxes
        for(short int i = 0; i < 9; ++i){
            for(short int digit = 1; digit <= 9; ++digit){
                line_vis_elem[i][digit] = 0;
                col_vis_elem[i][digit] = 0;
                sub_box_vis_elem[i][digit] = 0;
            }
        }
        
        short int vis_cnt = 0;
        for(short int i = 0 ; i < 9; ++i){
            for(short int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    short int digit = board[i][j] - '0';
                    short int sub_box_idx = 3 * (i / 3) + j / 3;
                    line_vis_elem[i][digit] = 1;
                    col_vis_elem[j][digit] = 1;
                    sub_box_vis_elem[sub_box_idx][digit] = 1;
                    ++vis_cnt;
                }
            }
        }
        
        // next position to fill
        fill(next_pos.begin(), next_pos.end(), -1);
        short int first_pos = -1;
        short int prev_pos = -1;
        for(short int i = 0; i < 9; ++i){
            for(short int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    short int cur_pos = 9 * i + j;
                    if(first_pos == -1){
                        first_pos = cur_pos;
                    }
                    if(prev_pos != -1){
                        next_pos[prev_pos] = cur_pos;
                    }
                    prev_pos = cur_pos;
                }
            }
        }
        
        // solve
        bool is_solved = 0;
        back(first_pos, vis_cnt, is_solved);
        
        // copy the solved board
        board = this->board;
    }
};