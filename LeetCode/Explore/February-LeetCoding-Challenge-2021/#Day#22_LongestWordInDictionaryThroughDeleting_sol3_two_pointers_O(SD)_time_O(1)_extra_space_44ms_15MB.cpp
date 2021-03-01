class Solution {
private:
    bool isValid(const string& WORD, const string& S){
        int pos = -1;
        for(char c: WORD){
            pos = S.find(c, pos + 1);
            if(pos == string::npos){
                return false;
            }
        }
        return true;
    }
    
public:
    string findLongestWord(string s, vector<string>& d) {
        string longestWord;
        for(const string& WORD: d){
            if(isValid(WORD, s)){
                if(WORD.size() > longestWord.size() || (WORD.size() == longestWord.size() && WORD < longestWord)){
                    longestWord = WORD;
                }
            }
        }
        return longestWord;
    }
};