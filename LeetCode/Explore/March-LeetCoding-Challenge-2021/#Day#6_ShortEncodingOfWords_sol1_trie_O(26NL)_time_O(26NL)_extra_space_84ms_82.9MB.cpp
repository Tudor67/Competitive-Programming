class Trie{
private:
    const static int ALPHABET_SIZE = 26;
    const static char FIRST_LETTER = 'a';
    vector<Trie*> children;
    bool isTerminalNode;
    
    int depthSum(Trie* node, int depth){
        int childrenDepthSum = 0;
        bool isLeaf = true;
        for(short int edgeID = 0; edgeID < Trie::ALPHABET_SIZE; ++edgeID){
            if(node->children[edgeID]){
                isLeaf = false;
                childrenDepthSum += depthSum(node->children[edgeID], depth + 1);
            }
        }
        if(isLeaf){
            return depth;
        }
        return childrenDepthSum;
    }
    
public:
    Trie(){
        children.resize(Trie::ALPHABET_SIZE, NULL);
        isTerminalNode = false;
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            short int edgeID = c - Trie::FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    int depthSum(){
        return depthSum(this, 1);
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        for(string word: words){
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
        return trie.depthSum();
    }
};