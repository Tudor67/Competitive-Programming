class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    int terminal_node_cnt;
    vector<TrieNode*> children;
    int max_word_freq;
    
    TrieNode(){
        this->terminal_node_cnt = 0;
        this->children.resize(ALPHABET_SIZE, NULL);
        this->max_word_freq = 0;
    }
    
    void insert(TrieNode* node, const string& word, int pos){
        if(pos == word.length()){
            node->terminal_node_cnt += 1;
            node->max_word_freq = max(node->terminal_node_cnt, node->max_word_freq);
        }else{
            short int edge_id = word[pos] - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            insert(node->children[edge_id], word, pos + 1);
            node->max_word_freq = max(node->children[edge_id]->max_word_freq, node->max_word_freq);
        }
    }
    
    void insert(const string& word){
        insert(this, word, 0);
    }

    void extract_top_k_freq_words(TrieNode* node, string& st, vector<string>& answer, bool& found){
        if(found){
            return;
        }
        
        int node_max_word_freq = node->max_word_freq;
        node->max_word_freq = 0;
        if(node->terminal_node_cnt > 0){
            found = true;
            node->terminal_node_cnt = 0;
            for(int edge_id = 0; edge_id < ALPHABET_SIZE; ++edge_id){
                TrieNode* next_node = node->children[edge_id];
                if(next_node){
                    node->max_word_freq = max(next_node->max_word_freq, node->max_word_freq);
                }
            }
            answer.push_back(st);
        }
        
        for(int edge_id = 0; edge_id < ALPHABET_SIZE; ++edge_id){
            TrieNode* next_node = node->children[edge_id];
            if(next_node && node_max_word_freq == next_node->max_word_freq){
                st.push_back(char(FIRST_LETTER + edge_id));
                extract_top_k_freq_words(next_node, st, answer, found);
                st.pop_back();
            }
            if(next_node){
                node->max_word_freq = max(next_node->max_word_freq, node->max_word_freq);                
            }
        }
    }    
    
    void extract_top_k_freq_words(int k, vector<string>& answer){
        for(; k > 0; --k){
            string st;
            bool found = false;
            extract_top_k_freq_words(this, st, answer, found);
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode* trie = new TrieNode();
        for(const string& word: words){
            trie->insert(word);
        }
        
        vector<string> answer;
        trie->extract_top_k_freq_words(k, answer);
        
        return answer;
    }
};