class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    const int MAX_BITS;
    int terminalNodesOfSubtree;
    Trie* children[ALPHABET_SIZE];
    
    void add(Trie* node, int x, int bit, const int& VAL){
        if(bit >= 0){
            int edgeID = ((x >> bit) & 1);
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie(MAX_BITS);
            }
            add(node->children[edgeID], x, bit - 1, VAL);
        }
        node->terminalNodesOfSubtree += 1;
    }
    
public:
    Trie(const int& MAX_BITS): MAX_BITS(MAX_BITS){
        terminalNodesOfSubtree = 0;
        for(int i = 0; i < Trie::ALPHABET_SIZE; ++i){
            children[i] = NULL;
        }
    }
    
    void add(int x){
        add(this, x, MAX_BITS - 1, 1);
    }
    
    int getTerminalNodesOfSubtree(){
        return terminalNodesOfSubtree;
    }
    
    Trie* getNextTrieNode(int edgeID){
        return children[edgeID];
    }
};

class Solution {
private:
    int countPairsLessOrEqual(const int& NUM, const int& MAX_NUM, Trie& trieRoot, const int& MAX_BITS){
        Trie* trieNode = &trieRoot;
        int count = 0;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            int numBitVal = ((NUM >> bit) & 1);
            int maxNumBitVal = ((MAX_NUM >> bit) & 1);
            if(maxNumBitVal == 1){
                if(trieNode->getNextTrieNode(numBitVal) != NULL){
                    count += trieNode->getNextTrieNode(numBitVal)->getTerminalNodesOfSubtree();
                }
            }
            trieNode = trieNode->getNextTrieNode(numBitVal ^ maxNumBitVal);
            if(trieNode == NULL){
                return count;
            }
        }
        count += trieNode->getTerminalNodesOfSubtree();
        return count;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        const int N = nums.size();
        
        const int MAX_VAL = max(high, *max_element(nums.begin(), nums.end()));
        const int MAX_BITS = (int)floor(log2(MAX_VAL)) + 1;
        
        int pairsCount = 0;
        Trie trie(MAX_BITS);
        for(int i = N - 1; i >= 0; --i){
            pairsCount += countPairsLessOrEqual(nums[i], high, trie, MAX_BITS);
            pairsCount -= countPairsLessOrEqual(nums[i], low - 1, trie, MAX_BITS);
            trie.add(nums[i]);
        }
        
        return pairsCount;
    }
};