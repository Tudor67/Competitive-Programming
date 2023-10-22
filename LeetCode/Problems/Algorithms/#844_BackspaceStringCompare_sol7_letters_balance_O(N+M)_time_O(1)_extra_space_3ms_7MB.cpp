class Solution {
private:
    char moveToPrevValidChar(string& s, int& i){
        int lettersBalance = 0;

        while(i >= 0){
            if(s[i] == '#'){
                lettersBalance -= 1;
            }else{
                lettersBalance += 1;
            }
            
            i -= 1;

            if(lettersBalance > 0){
                return s[i + 1];
            }
        }

        return -1;
    }

public:
    bool backspaceCompare(string s, string t) {
        char sChar = '.';
        char tChar = '.';

        int i = (int)s.length() - 1;
        int j = (int)t.length() - 1;
        while(sChar == tChar && (i >= 0 || j >= 0)){
            sChar = moveToPrevValidChar(s, i);
            tChar = moveToPrevValidChar(t, j);
        }

        return (sChar == tChar);
    }
};