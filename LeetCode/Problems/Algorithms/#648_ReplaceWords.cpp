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
    
    string extract_root_word(const string& word){
        TrieNode* node = this;
        for(int i = 0; i < word.length(); ++i){
            char c = word[i];
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return word;
            }
            if(node->children[edge_id]->is_terminal_node){
                return word.substr(0, i + 1);
            }
            node = node->children[edge_id];
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* trie = new TrieNode();
        for(const string& word: dict){
            trie->insert(word);
        }
        
        string answer;
        string word;
        for(int prev_pos = 0, pos = 0; pos <= sentence.length(); ++pos){
            if(pos == sentence.length() || sentence[pos] == ' '){
                word = sentence.substr(prev_pos, pos - prev_pos);
                answer += trie->extract_root_word(word) + " ";
                prev_pos = pos + 1;
            }
        }
        answer.pop_back(); // remove last space
        
        return answer;
    }
};