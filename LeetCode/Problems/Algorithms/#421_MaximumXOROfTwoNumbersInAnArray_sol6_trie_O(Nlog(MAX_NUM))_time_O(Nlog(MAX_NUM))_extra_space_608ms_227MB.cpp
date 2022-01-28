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
    
    void insert(int num, const int& MAX_BIT){
        Trie* node = this;
        for(int bit = MAX_BIT; bit >= 0; --bit){
            int edgeID = (num >> bit) & 1;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    int findMaxComplement(int num, const int& MAX_BIT){
        int maxComplement = 0;
        Trie* node = this;
        for(int bit = MAX_BIT; bit >= 0; --bit){
            int edgeID = (num >> bit) & 1;
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
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int maxBit = 0;
        if(MAX_NUM > 0){
            maxBit = floor(log2(MAX_NUM));
        }
        
        Trie trie;
        for(int num: nums){
            trie.insert(num, maxBit);
        }
        
        int maxXOR = 0;
        for(int num: nums){
            int numMaxComplement = trie.findMaxComplement(num, maxBit);
            maxXOR = max(maxXOR, num ^ numMaxComplement);
        }
        
        return maxXOR;
    }
};