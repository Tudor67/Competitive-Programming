class Solution {
private:
    bool lessOrEqual(const string& WORD1, const string& WORD2, const vector<int>& POS){
        for(int i = 0; i < (int)max(WORD1.length(), WORD2.length()); ++i){
            char c1 = (i < WORD1.length() ? WORD1[i] : ' ');
            char c2 = (i < WORD2.length() ? WORD2[i] : ' ');
            if(POS[c1] > POS[c2]){
                return false;
            }else if(POS[c1] < POS[c2]){
                return true;
            }
        }
        return true;
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(128, -1);
        for(int i = 0; i < (int)order.size(); ++i){
            pos[order[i]] = i;
        }
        
        for(int i = 0; i < (int)words.size() - 1; ++i){
            if(!lessOrEqual(words[i], words[i + 1], pos)){
                return false;
            }
        }
        
        return true;
    }
};