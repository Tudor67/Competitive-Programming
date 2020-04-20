class Solution {
private:
    void back(int k, short int i, short int j, const vector<vector<char>>& board, vector<vector<bool>>& vis,
              const string& word, bool& found){
        if(k == word.length()){
            found = true;
        }else{
            for(auto d: vector<pair<short int, short int>>{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}){
                short int next_i = i + d.first;
                short int next_j = j + d.second;
                bool valid = (next_i >= 0 && next_i < board.size() &&
                              next_j >= 0 && next_j < board[next_i].size() &&
                              !vis[next_i][next_j] && board[next_i][next_j] == word[k]);

                if(!found && valid){
                    vis[next_i][next_j] = 1;
                    back(k + 1, next_i, next_j, board, vis, word, found);
                    vis[next_i][next_j] = 0;
                }
            }
        }
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        // init
        int board_elems_cnt = 0;
        vector<vector<bool>> vis(board.size());
        for(short int i = 0; i < (int)board.size(); ++i){
            board_elems_cnt += board[i].size();
            vis[i].resize(board[i].size(), false);
        }
        
        // solve
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
        
        bool found = false;
        if(board_contains_all_word_letters && word.length() <= board_elems_cnt){
            for(short int i = 0; i < (int)board.size(); ++i){
                for(short int j = 0; j < (int)board[i].size(); ++j){
                    if(board[i][j] == word[0] && !found){
                        vis[i][j] = 1;
                        back(1, i, j, board, vis, word, found);
                        vis[i][j] = 0;
                    }
                }
            }
        }

        return found;
    }
};