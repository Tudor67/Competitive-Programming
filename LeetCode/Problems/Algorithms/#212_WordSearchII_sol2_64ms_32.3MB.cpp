class Config{
public:
    static const short int ALPHABET_LENGTH = 26;
    static const char FIRST_CHAR = 'a';
};

class TrieNode{
private:
    static const short int ALPHABET_LENGTH = Config::ALPHABET_LENGTH;
    static const char FIRST_CHAR = Config::FIRST_CHAR;
    
    void insert(const string& word, int k, TrieNode* node){
        short int edge_id = word[k] - FIRST_CHAR;
        if(node->children[edge_id] == NULL){
            node->children[edge_id] = new TrieNode();
        }
        
        if(k == (int)word.length() - 1){
            node->children[edge_id]->is_terminal_node = true;
        }else{
            insert(word, k + 1, node->children[edge_id]);
        }
    }
    
    bool contains(const string& word, int k, TrieNode* node){
        if(node == NULL){
            return false;
        }
        if(k == word.length()){
            return node->is_terminal_node;
        }
        
        short int edge_id = word[k] - FIRST_CHAR;
        return contains(word, k + 1, node->children[edge_id]);
    }
    
    void extract_words(int k, TrieNode* node, string& word, vector<string>& words){
        if(node != NULL){
            if(node->is_terminal_node){
                words.push_back(word);
            }
            for(short int edge_id = 0; edge_id < ALPHABET_LENGTH; ++edge_id){
                word.push_back(char(edge_id + FIRST_CHAR));
                extract_words(k + 1, node->children[edge_id], word, words);
                word.pop_back();
            }
        }
    }

public:
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(bool is_terminal_node = false) {
        this->is_terminal_node = is_terminal_node;
        this->children.resize(ALPHABET_LENGTH, NULL);
    }
    
    void insert(const string& word){
        insert(word, 0, this);
    }
    
    bool contains(const string& word){
        return contains(word, 0, this);
    }
    
    vector<string> extract_words(){
        vector<string> words; // words that were inserted in Trie until now (in lexicographical order)
        string word;          // current word in the stack (at level k)
        extract_words(0, this, word, words);
        return words;
    }
};

class Solution {
private:
    static const short int ALPHABET_LENGTH = Config::ALPHABET_LENGTH;
    static const char FIRST_CHAR = Config::FIRST_CHAR;
    const vector<short int> di = {0, 0, -1, 1};
    const vector<short int> dj = {-1, 1, 0, 0};
    
    void back(int k, string& word, const short int& i, const short int& j, vector<vector<char>>& board,
              TrieNode* trie_all_words, TrieNode& trie_found_words){
        if(trie_all_words != NULL){
            if(trie_all_words->is_terminal_node){
                trie_found_words.insert(word);
                trie_all_words->is_terminal_node = 0;
            }
            
            for(short int idx = 0; idx < di.size(); ++idx){
                short int next_i = i + di[idx];
                short int next_j = j + dj[idx];
                // valid_1: check if position (next_i, next_j) is inside the board and is not visited at this step
                bool valid_1 = (next_i >= 0 && next_i < board.size() &&
                                next_j >= 0 && next_j < board[next_i].size() &&
                                board[next_i][next_j] != '#');
                if(valid_1){
                    char next_char = board[next_i][next_j];
                    short int edge_id = next_char - FIRST_CHAR;
                    TrieNode* next_trie_all_words = trie_all_words->children[edge_id];
                    // valid_2: check if the next_char from position (next_i, next_j)
                    //          appears in at least one word at position k (i.e. next_char == word[k])
                    bool valid_2 = (next_trie_all_words != NULL);
                    if(valid_2){
                        word.push_back(next_char);
                        board[next_i][next_j] = '#';       // mark (next_i, next_j) as a visited position
                        back(k + 1, word, next_i, next_j, board, next_trie_all_words, trie_found_words);
                        board[next_i][next_j] = next_char; // unmark (next_i, next_j)
                        word.pop_back();
                    }
                }
            }
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode trie_all_words;   // trie with all (initial) words
        TrieNode trie_found_words; // trie with initial words that can be found in the board
        
        // init
        for(string& word: words){
            trie_all_words.insert(word);
        }
        
        // solve
        for(short int i = 0; i < board.size(); ++i){
            for(short int j = 0; j < board[i].size(); ++j){
                char c = board[i][j];
                short int edge_id = c - FIRST_CHAR;
                TrieNode* next_trie_all_words = trie_all_words.children[edge_id];
                if(next_trie_all_words != NULL){
                    string word(1, c); // current word in the stack (at level k)
                    board[i][j] = '#'; // mark (i, j) as a visited position
                    back(1, word, i, j, board, next_trie_all_words, trie_found_words);
                    board[i][j] = c;   // unmark (i, j)
                }
            }
        }

        return trie_found_words.extract_words();
    }
};