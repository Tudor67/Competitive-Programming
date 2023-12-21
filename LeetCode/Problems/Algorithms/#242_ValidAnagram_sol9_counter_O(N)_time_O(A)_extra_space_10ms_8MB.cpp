class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> balance;
        for(char c: s){
            balance[c] += 1;
        }

        for(char c: t){
            balance[c] -= 1;
        }

        for(pair<const char, int>& P: balance){
            if(P.second != 0){
                return false;
            }
        }

        return true;
    }
};