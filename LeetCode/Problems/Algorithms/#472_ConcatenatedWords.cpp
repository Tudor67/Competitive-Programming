class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& word){
        TrieNode* node = this;
        for(char c: word){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    bool is_concatenated_word(const string& word){
        const int n = word.length();
        vector<int> word_cnt(n, 0);
        
        for(int start_pos = 0; start_pos < n && word_cnt[n - 1] <= 1; ++start_pos){
            if(start_pos == 0 || word_cnt[start_pos - 1] > 0){
                TrieNode* node = this;
                for(int pos = start_pos; pos < n; ++pos){
                    short int edge_id = word[pos] - FIRST_LETTER;
                    if(node->children[edge_id] == NULL){
                        break;
                    }
                    node = node->children[edge_id];
                    word_cnt[pos] += node->is_terminal_node;
                }
            }
        }
        
        return (word_cnt[n - 1] > 1);
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(const string& word: words){
            trie->insert(word);
        }
        
        vector<string> answer;
        for(const string& word: words){
            if(!word.empty() && trie->is_concatenated_word(word)){
                answer.push_back(word);
            }
        }
        
        return answer;
    }
};