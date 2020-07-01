class TrieNode{
private:    
    void release_unused_memory(TrieNode* node, int pos, const string& word, bool& release_memory_flag){
        if(node != NULL && pos < word.length()){
            int edge_id = word[pos] - FIRST_LETTER;
            release_unused_memory(node->children[edge_id], pos + 1, word, release_memory_flag);
            release_memory_flag &= (!node->is_terminal_node && node->children_cnt == 1);
            if(release_memory_flag){
                delete node->children[edge_id];
                node->children[edge_id] = NULL;
            }
        }
    }
    
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    int children_cnt;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
        this->children_cnt = 0;
    }

    void insert(const string& word){
        TrieNode* node = this;
        for(char c: word){
            int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
                node->children_cnt += 1;
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    void remove(const string& word){
        TrieNode* node = this;
        for(char c: word){
            int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return;
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = false;
        if(node->children_cnt == 0){
            bool release_memory_flag = true;
            release_unused_memory(this, 0, word, release_memory_flag);
        }
    }
};

class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    bool is_inside_board(const int& i, const int& j, const vector<vector<char>>& board){
        return (i >= 0 && i < board.size() && j >= 0 && j < board[0].size());
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string& st, vector<string>& answer){
        if(node->is_terminal_node){
            answer.push_back(st);
            node->is_terminal_node = false;
        }
        for(const pair<int, int> direction: DIRECTIONS){
            int new_i = i + direction.first;
            int new_j = j + direction.second;
            if(is_inside_board(new_i, new_j, board) && board[new_i][new_j] != '#'){
                int edge_id = board[new_i][new_j] - TrieNode::FIRST_LETTER;
                if(node && node->children[edge_id]){
                    st.push_back(board[new_i][new_j]);
                    board[new_i][new_j] = '#';       // mark as visited
                    dfs(board, new_i, new_j, node->children[edge_id], st, answer);
                    board[new_i][new_j] = st.back(); // unmark
                    st.pop_back();
                }
            }
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(const string& word: words){
            trie->insert(word);
        }
        
        vector<string> answer;
        int prev_answer_size = 0;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                int edge_id = board[i][j] - TrieNode::FIRST_LETTER;
                if(answer.size() < words.size() && trie->children[edge_id]){
                    string st;
                    st.push_back(board[i][j]);
                    board[i][j] = '#';
                    dfs(board, i, j, trie->children[edge_id], st, answer);
                    board[i][j] = st.back();
                }
                
                for(int k = prev_answer_size; k < answer.size(); ++k){
                    trie->remove(answer[k]);
                }
                prev_answer_size = answer.size();
            }
        }
        
        return answer;
    }
};