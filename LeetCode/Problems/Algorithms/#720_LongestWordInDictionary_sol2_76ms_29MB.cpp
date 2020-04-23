class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    int max_len;
    int max_len_edge_id;
    
    TrieNode(bool is_terminal_node = false){
        this->is_terminal_node = is_terminal_node;
        this->children.resize(ALPHABET_SIZE, NULL);
        this->max_len = 0;
        this->max_len_edge_id = -1;
    }
    
    void insert(TrieNode* node, const string& word, int pos){
        if(pos == word.length()){
            node->is_terminal_node = true;
            node->max_len = 0;
            for(short int edge_id = 0; edge_id < ALPHABET_SIZE; ++edge_id){
                TrieNode* next_node = node->children[edge_id];
                if(next_node != NULL && next_node->is_terminal_node){
                    if(next_node->max_len + 1 > node->max_len ||
                       (next_node->max_len + 1 == node->max_len && edge_id < node->max_len_edge_id)){
                        node->max_len = next_node->max_len + 1;
                        node->max_len_edge_id = edge_id;
                    }
                }
            }
            if(node->max_len == 0){
                node->max_len = 1;
            }
        }else{
            short int edge_id = word[pos] - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            insert(node->children[edge_id], word, pos + 1);
            bool consecutive_terminal_nodes = (node->is_terminal_node && node->children[edge_id]->is_terminal_node);
            bool better_max = (node->children[edge_id]->max_len + 1 > node->max_len ||
                               (node->children[edge_id]->max_len + 1 == node->max_len &&
                                edge_id < node->max_len_edge_id));
            if(consecutive_terminal_nodes && better_max){
                // update max_len (lexicographical order in case of equality)
                node->max_len = node->children[edge_id]->max_len + 1;
                node->max_len_edge_id = edge_id;
            }
        }
    }
    
    void insert(const string& word){
        insert(this, word, 0);
    }
    
    string get_longest_word(){
        TrieNode* node = this;
        string longest_word;
        while(node->max_len_edge_id != -1){
            longest_word += char(node->max_len_edge_id + FIRST_LETTER);
            node = node->children[node->max_len_edge_id];
        }
        return longest_word;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        // mark root as a terminal node for convenience (for method get_longest_word())
        TrieNode* trie = new TrieNode(true);
        for(const string& word: words){
            trie->insert(word);
        }
        return trie->get_longest_word();
    }
};