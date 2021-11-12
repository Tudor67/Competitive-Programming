class Solution {
public:
    bool areOccurrencesEqual(string s) {
        const int MIN_ELEM = 'a';
        const int MAX_ELEM = 'z';
        
        vector<int> count(MAX_ELEM + 1, 0);
        for(char c: s){
            count[c] += 1;
        }
        
        const int FIXED_COUNT = count[s[0]];
        for(char c = MIN_ELEM; c <= MAX_ELEM; ++c){
            if(count[c] > 0 && count[c] != FIXED_COUNT){
                return false;
            }
        }
        
        return true;
    }
};