class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    int getTotalLength(Trie* node, int prefixLength){
        if(node == NULL){
            return 0;
        }
        int totalLength = 0;
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            totalLength += getTotalLength(node->children[edgeID], prefixLength + 1);
        }
        if(totalLength == 0){
            // node is a leaf
            totalLength = prefixLength + 1;
        }
        return totalLength;
    }
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int i = 0; i < ALPHABET_SIZE; ++i){
            delete children[i];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    int getTotalLength(){
        return getTotalLength(this, 0);
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        const int N = words.size();
        
        Trie trie;
        for(string& word: words){
            string reversedWord(word.rbegin(), word.rend());
            trie.insert(reversedWord);
        }
        
        return trie.getTotalLength();
    }
};