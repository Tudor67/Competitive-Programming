class Solution {
private:
    const vector<int> di = {0, 0, -1, 1};
    const vector<int> dj = {-1, 1, 0, 0};
    
    void back(int k, short int i, short int j, vector<vector<char>>& board, const string& word, bool& found){
        if(k == word.length()){
            found = true;
        }else{
            for(short int idx = 0; idx < 4; ++idx){
                short int next_i = i + di[idx];
                short int next_j = j + dj[idx];
                bool valid = (next_i >= 0 && next_i < board.size() &&
                              next_j >= 0 && next_j < board[next_i].size() &&
                              board[next_i][next_j] == word[k]);

                if(!found && valid){
                    char temp = board[next_i][next_j];
                    board[next_i][next_j] = '#';
                    back(k + 1, next_i, next_j, board, word, found);
                    board[next_i][next_j] = temp;
                }
            }
        }
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {        
        set<char> board_set;
        for(vector<char>& board_line: board){
            for(char c: board_line){
                board_set.insert(c);
            }
        }
        
        set<char> word_set;
        for(char c: word){
            word_set.insert(c);
        }
        
        bool board_contains_all_word_letters = 1;
        for(char c: word_set){
            board_contains_all_word_letters &= board_set.count(c);
        }
        
        int board_elems_cnt = 0;
        for(short int i = 0; i < (int)board.size(); ++i){
            board_elems_cnt += board[i].size();
        }
        
        bool found = false;
        if(board_contains_all_word_letters && word.length() <= board_elems_cnt){
            for(short int i = 0; i < (int)board.size(); ++i){
                for(short int j = 0; j < (int)board[i].size(); ++j){
                    if(board[i][j] == word[0] && !found){
                        char temp = board[i][j];
                        board[i][j] = '#';
                        back(1, i, j, board, word, found);
                        board[i][j] = temp;
                    }
                }
            }
        }

        return found;
    }
};