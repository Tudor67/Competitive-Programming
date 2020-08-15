class CombinationIterator {
private:
    int n;
    int k;
    string cur_comb;
    string last_comb;
    vector<char> next_char;
    bool is_first_call;
    
public:
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        k = combinationLength;
        cur_comb = characters.substr(0, k);
        last_comb = characters.substr(n - k);
        
        next_char.resize('z' + 5);
        for(int i = 1; i < n; ++i){
            next_char[characters[i - 1]] = characters[i];
        }
        
        is_first_call = true;
    }
    
    string next() {
        if(is_first_call){
            is_first_call = false;
        }else{
            for(int i = k - 1; i >= 0; --i){
                if(cur_comb[i] < last_comb[i]){
                    cur_comb[i] = next_char[cur_comb[i]];
                    for(int j = i + 1; j < k; ++j){
                        cur_comb[j] = next_char[cur_comb[j - 1]];
                    }
                    break;
                }
            }
        }
        return cur_comb;
    }
    
    bool hasNext() {
        return (cur_comb < last_comb);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */