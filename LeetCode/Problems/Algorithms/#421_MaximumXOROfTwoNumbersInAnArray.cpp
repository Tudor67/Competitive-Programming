class TrieNode{
public:
    static const int ALPHABET_SIZE = 2;
    static const char FIRST_ELEM = '0';
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& s){
        TrieNode* node = this;
        for(char c: s){
            short int edge_id = c - FIRST_ELEM;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    int get_best_complement(const string& s){
        TrieNode* node = this;
        int complement = 0;
        for(char c: s){
            short int edge_id = !(c - FIRST_ELEM); // try complement
            if(node->children[edge_id] == NULL){
                edge_id = !edge_id;
            }
            node = node->children[edge_id];
            complement = 2 * complement + edge_id;
        }
        return complement;
    }
};

class Solution {
private:
    string binary_representation(int num, int expected_size = 32){
        string s;
        if(num == 0){
            s = string(expected_size, '0');
        }else{
            while(num > 0){
                s += char('0' + num % 2);
                num /= 2;
            }
            while(s.length() < expected_size){
                s += "0";
            }
            reverse(s.begin(), s.end());
        }
        return s;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<string> nums_str(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            nums_str[i] = binary_representation(nums[i]);
        }
        
        TrieNode* trie = new TrieNode();
        for(int i = 0; i < nums_str.size(); ++i){
            trie->insert(nums_str[i]);
        }
        
        int answer = 0;
        for(int i = 0; i < nums.size(); ++i){
            int complement = trie->get_best_complement(nums_str[i]);
            answer = max(nums[i] ^ complement, answer);
        }
        
        return answer;
    }
};