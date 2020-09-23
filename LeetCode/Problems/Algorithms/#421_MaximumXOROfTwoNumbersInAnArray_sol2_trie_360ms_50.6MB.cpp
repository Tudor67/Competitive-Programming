class TrieNode{
public:
    static const int ALPHABET_SIZE = 2;
    static const int FIRST_LETTER = '0';
    bool isTerminalNode;
    vector<TrieNode*> children;
    
    TrieNode(){
        isTerminalNode = false;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& WORD){
        TrieNode* node = this;
        for(char c: WORD){
            short int edgeID = c - FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new TrieNode();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    string findClosestComplement(const string& WORD){
        string closestComplement;
        TrieNode* node = this;
        for(char c: WORD){
            short int edgeID = c - FIRST_LETTER;
            if(node->children[edgeID ^ 1]){
                closestComplement += char(FIRST_LETTER + (edgeID ^ 1));
                node = node->children[edgeID ^ 1];
            }else{
                closestComplement += char(FIRST_LETTER + edgeID);
                node = node->children[edgeID];
            }
        }
        return closestComplement;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* trie = new TrieNode();
        
        for(int num: nums){
            string numBinaryRepresentation = bitset<31>(num).to_string();
            trie->insert(numBinaryRepresentation);
        }
        
        int maxXOR = 0;
        for(int num: nums){
            string numBinaryRepresentation = bitset<31>(num).to_string();
            string numClosestComplementBinaryRepresentation = trie->findClosestComplement(numBinaryRepresentation);
            int numClosestComplement = stoi(numClosestComplementBinaryRepresentation, NULL, 2);
            maxXOR = max(num ^ numClosestComplement, maxXOR);
        }
        
        return maxXOR;
    }
};