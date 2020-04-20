class CombinationIterator {
private:
    int n;
    int k;
    string characters;
    string cur_comb;
    string last_comb;
    vector<int> st;
    bool is_first_call_of_next;
    
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        this->n = characters.length();
        this->k = combinationLength;
        
        cur_comb = characters.substr(0, k);
        last_comb = characters.substr(n - k);
        
        st.resize(k);
        iota(st.begin(), st.end(), 0);
        
        is_first_call_of_next = 1;
    }
    
    string next() {
        if(!is_first_call_of_next){
            for(int i = k - 1; i >= 0; --i){
                if(cur_comb[i] < last_comb[i]){
                    ++st[i];
                    cur_comb[i] = characters[st[i]];
                    for(int j = i + 1; j < k; ++j){
                        st[j] = st[j - 1] + 1;
                        cur_comb[j] = characters[st[j]];
                    }
                    break;
                }
            }
        }
        is_first_call_of_next = 0;
        return cur_comb;
    }
    
    bool hasNext() {
        return cur_comb < last_comb;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */