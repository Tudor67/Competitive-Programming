class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    int count;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        count = 0;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void addWord(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->count += 1;
        }
    }
    
    int getLengthOfLongestCommonPrefix(const string& WORD, const int& TARGET_COUNT){
        Trie* node = this;
        int maxLength = 0;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] != nullptr && node->children[edgeID]->count == TARGET_COUNT){
                maxLength += 1;
                node = node->children[edgeID];
            }else{
                break;
            }
        }
        return maxLength;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = strs.size();
        
        Trie trie;
        for(const string& S: strs){
            trie.addWord(S);
        }
        
        return strs[0].substr(0, trie.getLengthOfLongestCommonPrefix(strs[0], N));
    }
};