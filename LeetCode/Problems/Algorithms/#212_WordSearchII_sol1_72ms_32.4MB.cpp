class Config{
public:
    static const int ALPHABET_LENGTH = 26;
    static const char FIRST_CHAR = 'a';
};

class Trie{
private:
    static const int ALPHABET_LENGTH = Config::ALPHABET_LENGTH;
    static const char FIRST_CHAR = Config::FIRST_CHAR;
    bool is_terminal_node;
    vector<Trie*> next_node; // next nodes keep pointers to Trie objects (or NULL)
    
    void insert(const string& word, int k, Trie* trie){
        int edge_id = word[k] - FIRST_CHAR;
        if(trie->get_next_node(edge_id) == NULL){
            trie->set_next_node(edge_id);
        }
        
        Trie* next_trie = trie->get_next_node(edge_id);
        if(k == (int)word.length() - 1){
            next_trie->is_terminal_node = true;
        }else{
            insert(word, k + 1, next_trie);
        }
    }
    
    bool contains(const string& word, int k, Trie* trie){
        if(trie == NULL){
            return false;
        }
        if(k == word.length()){
            return trie->is_terminal_node;
        }
        
        int edge_id = word[k] - FIRST_CHAR;
        return contains(word, k + 1, trie->get_next_node(edge_id));
    }
    
    void extract_words(int k, Trie* trie, string& word, vector<string>& words){
        if(trie != NULL){
            if(trie->is_terminal_node){
                words.push_back(word);
            }
            for(int edge_id = 0; edge_id < ALPHABET_LENGTH; ++edge_id){
                word.push_back(char(edge_id + FIRST_CHAR));
                extract_words(k + 1, trie->get_next_node(edge_id), word, words);
                word.pop_back();
            }
        }
    }

public:
    Trie(bool is_terminal_node = false) {
        this->is_terminal_node = is_terminal_node;
        this->next_node.resize(ALPHABET_LENGTH, NULL);
    }
    
    bool is_terminal_node_getter(){
        return is_terminal_node;
    }

    Trie* get_next_node(int edge_id){
        return next_node[edge_id];
    }
    
    void set_next_node(int edge_id){
        next_node[edge_id] = new Trie();
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
    static const int ALPHABET_LENGTH = Config::ALPHABET_LENGTH;
    static const char FIRST_CHAR = Config::FIRST_CHAR;
    const vector<int> di = {0, 0, -1, 1};
    const vector<int> dj = {-1, 1, 0, 0};
    
    void back(int k, string& word, const int& i, const int& j, vector<vector<char>>& board, Trie* trie_all_words, Trie& trie_found_words){
        if(trie_all_words != NULL){
            if(trie_all_words->is_terminal_node_getter()){
                trie_found_words.insert(word);
            }
            
            for(int idx = 0; idx < di.size(); ++idx){
                int next_i = i + di[idx];
                int next_j = j + dj[idx];
                // valid_1: check if position (next_i, next_j) is inside the board and is not visited at this step
                bool valid_1 = (next_i >= 0 && next_i < board.size() &&
                                next_j >= 0 && next_j < board[next_i].size() &&
                                board[next_i][next_j] != '#');
                if(valid_1){
                    char next_char = board[next_i][next_j];
                    int edge_id = next_char - FIRST_CHAR;
                    Trie* next_trie_all_words = trie_all_words->get_next_node(edge_id);
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
        Trie trie_all_words;   // trie with all (initial) words
        Trie trie_found_words; // trie with initial words that can be found in the board
        
        // init
        for(string& word: words){
            trie_all_words.insert(word);
        }
        
        // solve
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                char c = board[i][j];
                int edge_id = c - FIRST_CHAR;
                Trie* next_trie_all_words = trie_all_words.get_next_node(edge_id);
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