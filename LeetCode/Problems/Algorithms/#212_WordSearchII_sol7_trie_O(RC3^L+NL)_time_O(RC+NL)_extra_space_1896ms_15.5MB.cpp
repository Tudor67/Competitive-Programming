class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool hasChild(char c){
        int edgeID = c - FIRST_CHAR;
        return (0 <= edgeID && edgeID < ALPHABET_SIZE && children[edgeID] != nullptr);
    }
    
    Trie* getChild(char c){
        if(hasChild(c)){
            int edgeID = c - FIRST_CHAR;
            return children[edgeID];
        }
        return nullptr;
    }
};

class Solution {
private:
    void back(int row, int col, string& word, Trie* node, vector<vector<char>>& board, vector<string>& res){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        if(node->hasChild(board[row][col])){
            node = node->getChild(board[row][col]);
            
            word.push_back(board[row][col]);
            if(node->isTerminalNode){
                res.push_back(word);
                node->isTerminalNode = false;
            }
            
            char originalChar = board[row][col];
            board[row][col] = '#';
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    back(nextRow, nextCol, word, node, board, res);
                }
            }
            
            board[row][col] = originalChar;
            word.pop_back();
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        Trie trie;
        for(const string& WORD: words){
            if((int)WORD.length() <= ROWS * COLS){
                trie.insert(WORD);
            }
        }
        
        string word;
        vector<vector<char>> boardCopy = board;
        vector<string> res;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                back(row, col, word, &trie, boardCopy, res);
            }
        }
        
        return res;
    }
};