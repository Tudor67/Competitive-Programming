class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int val;
    int sum;
    vector<Trie*> children;
    
    Trie* getNode(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - Trie::FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return NULL;
            }
            node = node->children[edgeID];
        }
        return node;
    }
    
public:
    Trie(){
        val = 0;
        sum = 0;
        children.resize(Trie::ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& WORD, const int& VAL){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - Trie::FIRST_ELEM;
            if(!node->children[edgeID]){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->val = VAL;
    }
    
    void addAllPrefixSums(const string& WORD, const int& VAL){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - Trie::FIRST_ELEM;
            if(!node->children[edgeID]){
                node->children[edgeID] = new Trie();
            }
            node->children[edgeID]->sum += VAL;
            node = node->children[edgeID];
        }
    }
    
    int getVal(const string& WORD){
        Trie* node = getNode(WORD);
        if(node){
            return node->val;
        }
        return 0;
    }
    
    int getPrefixSum(const string& WORD){
        Trie* node = getNode(WORD);
        if(node){
            return node->sum;
        }
        return 0;
    }
};

class MapSum {
private:
    Trie trie;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        const int VAL_TO_ADD = val - trie.getVal(key);
        trie.addAllPrefixSums(key, VAL_TO_ADD);
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.getPrefixSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */