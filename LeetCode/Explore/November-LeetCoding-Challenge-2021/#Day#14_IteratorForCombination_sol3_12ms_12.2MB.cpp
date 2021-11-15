class CombinationIterator {
private:
    int n;
    int k;
    string currentCombination;
    string lastCombination;
    vector<int> nextChar;
    bool isFirstCallOfNext;
    
public:
    CombinationIterator(string characters, int combinationLength) {
        n = characters.length();
        k = combinationLength;
        
        currentCombination = characters.substr(0, k);
        lastCombination = characters.substr(n - k);
        
        nextChar.resize('z' + 1);
        for(int i = 0; i + 1 < n; ++i){
            nextChar[characters[i]] = characters[i + 1];
        }
        
        isFirstCallOfNext = true;
    }
    
    string next() {
        if(isFirstCallOfNext){
            isFirstCallOfNext = false;
            return currentCombination;
        }
        for(int i = k - 1; i >= 0; --i){
            if(currentCombination[i] < lastCombination[i]){
                currentCombination[i] = nextChar[currentCombination[i]];
                for(int j = i + 1; j < k; ++j){
                    currentCombination[j] = nextChar[currentCombination[j - 1]];
                }
                return currentCombination;
            }
        }
        return "";
    }
    
    bool hasNext() {
        return (isFirstCallOfNext || currentCombination < lastCombination);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */