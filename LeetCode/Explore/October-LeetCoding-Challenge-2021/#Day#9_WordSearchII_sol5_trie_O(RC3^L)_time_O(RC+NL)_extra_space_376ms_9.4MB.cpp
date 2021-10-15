class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
};

class Solution {
private:
    void back(int row, int col, Trie* trie, string& st, vector<vector<bool>>& vis,
              const vector<vector<char>>& BOARD, vector<string>& answer){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = BOARD.size();
        const int COLS = BOARD[0].size();
        int edgeID = BOARD[row][col] - Trie::FIRST_ELEM;
        if(trie->children[edgeID] == NULL){
            return;
        }
        st.push_back(BOARD[row][col]);
        if(trie->children[edgeID]->isTerminalNode){
            answer.push_back(st);
            trie->children[edgeID]->isTerminalNode = false;
        }
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                back(nextRow, nextCol, trie->children[edgeID], st, vis, BOARD, answer);
            }
        }
        vis[row][col] = false;
        st.pop_back();
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        int boardCharsMask = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                boardCharsMask |= (1 << (board[row][col] - 'a'));
            }
        }
        
        Trie* trie = new Trie();
        for(const string& WORD: words){
            if(WORD.length() <= ROWS * COLS){
                int wordMask = 0;
                for(char c: WORD){
                    wordMask |= (1 << (c - 'a'));
                }
                if((boardCharsMask & wordMask) == wordMask){
                    trie->insert(WORD);
                }
            }
        }
        
        string st;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        vector<string> answer;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                back(row, col, trie, st, vis, board, answer);
            }
        }
        
        return answer;
    }
};