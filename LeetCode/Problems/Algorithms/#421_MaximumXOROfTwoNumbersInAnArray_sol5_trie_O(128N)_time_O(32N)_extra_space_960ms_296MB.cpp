class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    static const int FIRST_ELEM = '0';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    int findMaxComplement(const string& WORD){
        int maxComplement = 0;
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[1 - edgeID] != NULL){
                maxComplement = 2 * maxComplement + (1 - edgeID);
                node = node->children[1 - edgeID];
            }else{
                maxComplement = 2 * maxComplement + edgeID;
                node = node->children[edgeID];
            }
        }
        return maxComplement;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        const int N = nums.size();
        
        Trie trie;
        for(int num: nums){
            string numBinRepr = bitset<31>(num).to_string();
            trie.insert(numBinRepr);
        }
        
        int maxXOR = 0;
        for(int num: nums){
            string numBinRepr = bitset<31>(num).to_string();
            int numMaxComplement = trie.findMaxComplement(numBinRepr);
            maxXOR = max(maxXOR, num ^ numMaxComplement);
        }
        
        return maxXOR;
    }
};