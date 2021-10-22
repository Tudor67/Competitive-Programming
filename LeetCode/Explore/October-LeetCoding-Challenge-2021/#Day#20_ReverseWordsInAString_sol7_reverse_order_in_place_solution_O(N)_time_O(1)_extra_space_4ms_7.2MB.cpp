class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        reverse(s.begin(), s.end());
        s += ' ';
        
        int startPos = 0;
        int endPos = -1;
        for(int i = 0; i <= N; ++i){
            if(s[i] == ' '){
                if(startPos <= endPos){
                    reverse(s.begin() + startPos, s.begin() + endPos + 1);
                    s[++endPos] = ' ';
                    startPos = endPos + 1;
                }
            }else{
                s[++endPos] = s[i];
            }
        }
        
        s.resize(endPos);
        
        return s;
    }
};