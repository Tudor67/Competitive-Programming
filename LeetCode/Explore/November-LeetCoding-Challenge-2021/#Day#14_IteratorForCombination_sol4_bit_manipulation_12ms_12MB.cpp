class CombinationIterator {
private:
    string characters;
    int n;
    int k;
    int fullMask;
    int mask;
    
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        this->n = characters.length();
        this->k = combinationLength;
        this->fullMask = (1 << n) - 1;
        this->mask = fullMask;
    }
    
    string next() {
        if(!hasNext()){
            return "";
        }
        string combination;
        for(int bit = n - 1, i = 0; bit >= 0; --bit, ++i){
            if((mask >> bit) & 1){
                combination += characters[i];
            }
        }
        --mask;
        return combination;
    }
    
    bool hasNext() {
        while(mask > 0 && __builtin_popcount((unsigned int)mask) != k){
            --mask;
        }
        return (mask > 0);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */