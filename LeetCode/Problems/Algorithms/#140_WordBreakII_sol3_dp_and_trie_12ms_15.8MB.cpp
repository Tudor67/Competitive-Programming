class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(bool is_terminal_node = false){
        this->is_terminal_node = is_terminal_node;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& word){
        TrieNode* node = this;
        for(char c: word){
            int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    bool contains(const string& word){
        TrieNode* node = this;
        for(char c: word){
            int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return false;
            }
            node = node->children[edge_id];
        }
        return node->is_terminal_node;
    }
};

class Solution {
private:
    void back(int k, vector<int>& st, const string& s, vector<string>& answer, const vector<vector<int>>& dp){
        if(st[k] == 0){
            answer.push_back("");
            for(int i = k - 1; i >= 0; --i){
                for(int j = st[i + 1] + 1; j <= st[i]; ++j){
                    answer.back().push_back(s[j]);
                }
                if(i > 0){
                    answer.back() += " ";
                }
            }
        }else{
            for(int prev_pos: dp[st[k]]){
                st[k + 1] = prev_pos - 1;
                back(k + 1, st, s, answer, dp);
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {        
        s = "#" + s;
        const int n = (int)s.length() - 1;
        
        TrieNode* trie = new TrieNode();
        int min_word_length = n + 5;
        int max_word_length = 0;
        for(const string& word: wordDict){
            trie->insert(word);
            min_word_length = min((int)word.length(), min_word_length);
            max_word_length = max((int)word.length(), max_word_length);
        }
        
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[0].push_back(0);
        
        for(int start_pos = 1; start_pos <= n + 1 - min_word_length; ++start_pos){
            if(!dp[start_pos - 1].empty()){
                for(int len = min_word_length; len + start_pos - 1 <= n && len <= max_word_length; ++len){
                    if(trie->contains(s.substr(start_pos, len))){
                        dp[start_pos + len - 1].push_back(start_pos);
                    }
                }
            }
        }
        
        vector<string> answer;
        vector<int> st(n + 5);
        st[0] = n;
        back(0, st, s, answer, dp);
        
        return answer;
    }
};