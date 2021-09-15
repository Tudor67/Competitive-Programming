class Solution {
public:
    string reverseOnlyLetters(string s) {
        const int N = s.length();
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(!isalpha(s[i])){
                i += 1;
            }else if(!isalpha(s[j])){
                j -= 1;
            }else{
                swap(s[i], s[j]);
                i += 1;
                j -= 1;
            }
        }
        return s;
    }
};