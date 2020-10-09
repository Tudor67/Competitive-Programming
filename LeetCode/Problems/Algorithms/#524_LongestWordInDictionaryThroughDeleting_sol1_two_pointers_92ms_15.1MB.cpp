class Solution {
private:
    bool isPossible(const string& S, const string& WORD){
        int i = 0;
        int j = 0;
        while(i < S.length() && j < WORD.length()){
            while(i < S.length() && S[i] != WORD[j]){
                i += 1;
            }
            if(i == S.length()){
                return false;
            }
            i += 1;
            j += 1;
        }
        return (j == WORD.length());
    }
    
public:
    string findLongestWord(string s, vector<string>& d) {
        string answer;
        for(const string& WORD: d){
            if(isPossible(s, WORD)){
                if(WORD.length() > answer.length() || (WORD.length() == answer.length() && WORD < answer)){
                    answer = WORD;
                }
            }
        }
        return answer;
    }
};