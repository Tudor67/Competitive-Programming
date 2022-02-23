class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        int startPos = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == ' '){
                startPos = i + 1;
            }else if(i + 1 == N || s[i + 1] == ' '){
                reverse(s.begin() + startPos, s.begin() + i + 1);
            }
        }
        
        return s;
    }
};