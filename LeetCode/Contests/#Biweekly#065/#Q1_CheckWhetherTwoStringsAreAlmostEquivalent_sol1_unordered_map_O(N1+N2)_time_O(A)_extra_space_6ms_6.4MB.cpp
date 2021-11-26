class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> balance;
        
        for(char c: word1){
            balance[c] += 1;
        }
        
        for(char c: word2){
            balance[c] -= 1;
        }
        
        for(const pair<char, int>& P: balance){
            if(abs(P.second) >= 4){
                return false;
            }
        }
        
        return true;
    }
};