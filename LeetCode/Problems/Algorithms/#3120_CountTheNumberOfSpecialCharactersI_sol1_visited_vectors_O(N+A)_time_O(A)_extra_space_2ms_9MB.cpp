class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int A = 26;

        vector<bool> visLower(A, false);
        vector<bool> visUpper(A, false);
        for(char c: word){
            if(islower(c)){
                visLower[c - 'a'] = true;
            }else{
                visUpper[c - 'A'] = true;
            }
        }

        int specialLetters = 0;
        for(int i = 0; i < A; ++i){
            if(visLower[i] && visUpper[i]){
                ++specialLetters;
            }
        }

        return specialLetters;
    }
};