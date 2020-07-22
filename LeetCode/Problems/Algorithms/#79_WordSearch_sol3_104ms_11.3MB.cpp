class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void back(int i, int j, vector<vector<char>>& board, const string& WORD, int pos, bool& found){
        if(pos == WORD.length()){
            found = true;
        }else{
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int new_i = i + DIRECTION.first;
                int new_j = j + DIRECTION.second;
                bool is_inside = (new_i >= 0 && new_i < board.size() &&
                                  new_j >= 0 && new_j < board[new_i].size());
                if(!found && is_inside && board[new_i][new_j] == WORD[pos]){
                    board[new_i][new_j] = '#';       // mark as visited
                    back(new_i, new_j, board, WORD, pos + 1, found);
                    board[new_i][new_j] = WORD[pos]; // unmark
                }
            }
        }
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(!found && board[i][j] == word[0]){
                    board[i][j] = '#';
                    back(i, j, board, word, 1, found);
                    board[i][j] = word[0];
                }
            }
        }
        return found;
    }
};