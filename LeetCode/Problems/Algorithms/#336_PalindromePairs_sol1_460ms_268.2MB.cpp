class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    vector<int> word_ids;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert_reversed(const string& word, const int& word_id){
        TrieNode* node = this;
        for(int i = (int)word.length() - 1; i >= 0; --i){
            short int edge_id = word[i] - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
        node->word_ids.push_back(word_id);
    }
};

class Solution {
private:
    bool is_palindrome(const string& word){
        for(int i = 0, j = (int)word.length() - 1; i < j; ++i, --j){
            if(word[i] != word[j]){
                return false;
            }
        }
        return true;
    }

    void update_answer(const int& id1, const vector<int>& ids2, vector<vector<int>>& answer){
        for(int id2: ids2){
            if(id1 != id2){
                answer.push_back({id1, id2});
            }
        }
    }
    
    void save_all_palindrome_prefixes(TrieNode* node, string& st,
                                      const int& word_id, vector<vector<int>>& answer){
        if(node != NULL){
            if(node->is_terminal_node && !st.empty() && is_palindrome(st)){
                update_answer(word_id, node->word_ids, answer);
            }
            
            for(short int edge_id = 0; edge_id < TrieNode::ALPHABET_SIZE; ++edge_id){
                if(node->children[edge_id]){
                    st.push_back(char(edge_id + TrieNode::FIRST_LETTER));
                    save_all_palindrome_prefixes(node->children[edge_id], st, word_id, answer);
                    st.pop_back();
                }
            }
        }
    }
    
    void add_palindrome_pairs(const string& word, const int& word_id,
                              TrieNode* trie, vector<vector<int>>& answer){
        TrieNode* node = trie;
        
        if(node->is_terminal_node && is_palindrome(word)){
            update_answer(word_id, node->word_ids, answer);
        }
        
        for(int i = 0; i < word.length(); ++i){
            short int edge_id = word[i] - TrieNode::FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                // we cannot find more palindrome pairs for words[word_id]
                node = NULL;
                break;
            }
            node = node->children[edge_id];
            if(node->is_terminal_node && is_palindrome(word.substr(i + 1))){
                update_answer(word_id, node->word_ids, answer);
            }
        }
        
        if(node != NULL){
            string st;
            save_all_palindrome_prefixes(node, st, word_id, answer);
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(int i = 0; i < words.size(); ++i){
            trie->insert_reversed(words[i], i);
        }
        
        vector<vector<int>> answer;
        for(int i = 0; i < words.size(); ++i){
            add_palindrome_pairs(words[i], i, trie, answer);
        }
        return answer;
    }
};