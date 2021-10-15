class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    int subtreeTerminalNodes;
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        subtreeTerminalNodes = 0;
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
        node->subtreeTerminalNodes += 1;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->subtreeTerminalNodes += 1;
        }
        node->isTerminalNode = true;
    }
};

class Solution {
private:
    void back(int row, int col, Trie* trie, vector<Trie*>& trieStack, string& st, vector<vector<bool>>& vis,
              const vector<vector<char>>& BOARD, vector<string>& answer){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = BOARD.size();
        const int COLS = BOARD[0].size();
        int edgeID = BOARD[row][col] - Trie::FIRST_ELEM;
        if(trie->children[edgeID] == NULL || trie->children[edgeID]->subtreeTerminalNodes == 0){
            return;
        }
        trieStack.push_back(trie->children[edgeID]);
        st.push_back(BOARD[row][col]);
        vis[row][col] = true;
        if(trie->children[edgeID]->isTerminalNode){
            answer.push_back(st);
            for(Trie* node: trieStack){
                node->subtreeTerminalNodes -= 1;
            }
            trie->children[edgeID]->isTerminalNode = false;
        }
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                back(nextRow, nextCol, trie->children[edgeID], trieStack, st, vis, BOARD, answer);
            }
        }
        vis[row][col] = false;
        st.pop_back();
        trieStack.pop_back();
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
        
        vector<Trie*> trieStack;
        string st;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        vector<string> answer;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                back(row, col, trie, trieStack, st, vis, board, answer);
            }
        }
        
        return answer;
    }
};