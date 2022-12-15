class Solution {
public:
    bool isCircularSentence(string s) {
        const int N = s.length();
        
        if(s.front() != s.back()){
            return false;
        }
        
        for(int i = 0; i < N; ++i){
            if(s[i] == ' ' && s[i - 1] != s[i + 1]){
                return false;
            }
        }
        
        return true;
    }
};