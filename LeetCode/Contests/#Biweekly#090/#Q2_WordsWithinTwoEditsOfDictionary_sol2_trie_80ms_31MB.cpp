class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    bool match(Trie* node, int index, const string& WORD, int remainingEdits){
        if(node == nullptr || remainingEdits < 0){
            return false;
        }
        if(index == (int)WORD.length()){
            return node->isTerminalNode;
        }
        bool found = false;
        for(int edgeID = 0; edgeID < ALPHABET_SIZE && !found; ++edgeID){
            found = found || match(node->children[edgeID], index + 1, WORD,
                                   remainingEdits - (int)(WORD[index] != char(edgeID + FIRST_CHAR)));
        }
        return found;
    }
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool match(const string& WORD, int remainingEdits = 0){
        return match(this, 0, WORD, remainingEdits);
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const int N = dictionary.size();
        const int Q = queries.size();
        
        Trie trie;
        for(const string& S: dictionary){
            trie.insert(S);
        }
        
        vector<string> res;
        for(const string& S: queries){
            if(trie.match(S, 2)){
                res.push_back(S);
            }
        }
        
        return res;
    }
};