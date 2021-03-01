class Solution {
private:
    bool isValid(const string& WORD, const string& S, const vector<vector<int>>& NEXT_POS){
        int pos = -1;
        for(char c: WORD){
            pos = NEXT_POS[pos + 1][c - 'a'];
            if(pos == (int)S.length()){
                return false;
            }
        }
        return true;
    }
    
public:
    string findLongestWord(string s, vector<string>& d) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        
        vector<vector<int>> nextPos(N + 1, vector<int>(ALPHABET_SIZE, N));
        // nextPos[i][charIdx]: pos of char('a' + charIdx) in S[i..]
        for(int i = N - 1; i >= 0; --i){
            nextPos[i] = nextPos[i + 1];
            nextPos[i][s[i] - 'a'] = i;
        }
        
        string longestWord;
        for(const string& WORD: d){
            if(isValid(WORD, s, nextPos)){
                if(WORD.size() > longestWord.size() || (WORD.size() == longestWord.size() && WORD < longestWord)){
                    longestWord = WORD;
                }
            }
        }
        
        return longestWord;
    }
};