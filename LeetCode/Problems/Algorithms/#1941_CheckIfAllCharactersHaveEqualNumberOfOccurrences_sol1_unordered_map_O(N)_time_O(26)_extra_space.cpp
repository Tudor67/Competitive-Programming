class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
        }
        
        const int FIXED_COUNT = count[s[0]];
        for(const pair<char, int>& P: count){
            if(FIXED_COUNT != P.second){
                return false;
            }
        }
        
        return true;
    }
};