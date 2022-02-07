class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> bal(128);
        for(char c: s){
            bal[c] += 1;
        }
        
        for(char c: t){
            bal[c] -= 1;
        }
        
        for(int i = 0; i < (int)bal.size(); ++i){
            if(bal[i] == -1){
                return i;
            }
        }
        
        return -1;
    }
};