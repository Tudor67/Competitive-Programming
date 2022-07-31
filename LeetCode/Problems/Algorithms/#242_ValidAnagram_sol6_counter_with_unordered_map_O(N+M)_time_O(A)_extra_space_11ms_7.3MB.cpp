class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> balance;
        
        for(char c: s){
            balance[c] += 1;
        }
        
        for(char c: t){
            balance[c] -= 1;
        }
        
        for(const pair<char, int>& P: balance){
            char c = P.first;
            char cBalance = P.second;
            if(cBalance != 0){
                return false;
            }
        }
        
        return true;
    }
};