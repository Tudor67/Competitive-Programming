class Trie{
private:
    static const int ALPHABET_SIZE = 2;
    static const int FIRST_ELEM = '0';
    int prefCount;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        prefCount = 0;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void add(int num, const int MAX_BITS){
        Trie* node = this;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            int edgeID = (num >> bit) & 1;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->prefCount += 1;
        }
    }
    
    void erase(int num, const int MAX_BITS){
        Trie* node = this;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            int edgeID = (num >> bit) & 1;
            node = node->children[edgeID];
            node->prefCount -= 1;
        }
    }
    
    int getMaxXOR(int num, const int MAX_BITS){
        int maxXOR = 0;
        Trie* node = this;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            int edgeID = (num >> bit) & 1;
            if(node->children[1 - edgeID] != nullptr && node->children[1 - edgeID]->prefCount >= 1){
                node = node->children[1 - edgeID];
                maxXOR = (maxXOR << 1) | 1;
            }else{
                node = node->children[edgeID];
                maxXOR = (maxXOR << 1);
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BITS = 20;
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int maxXOR = 0;
        Trie trie;
        
        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < N && 2 * sortedNums[i] >= sortedNums[j]){
                trie.add(sortedNums[j], MAX_BITS);
                j += 1;
            }
            maxXOR = max(maxXOR, trie.getMaxXOR(sortedNums[i], MAX_BITS));
            trie.erase(sortedNums[i], MAX_BITS);
        }
        
        return maxXOR;
    }
};