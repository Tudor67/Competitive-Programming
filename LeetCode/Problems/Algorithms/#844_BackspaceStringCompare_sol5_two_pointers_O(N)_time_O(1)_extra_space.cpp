class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = (int)s.length() - 1;
        int j = (int)t.length() - 1;
        
        int sSkip = 0;
        int tSkip = 0;
        while(i > -1 || j > -1){
            while(i > -1 && (s[i] == '#' || sSkip > 0)){
                if(s[i] == '#'){
                    sSkip += 1;
                }else{
                    sSkip -= 1;
                }
                i -= 1;
            }
            
            while(j > -1 && (t[j] == '#' || tSkip > 0)){
                if(t[j] == '#'){
                    tSkip += 1;
                }else{
                    tSkip -= 1;
                }
                j -= 1;
            }
            
            if(i > -1 && j > -1 && s[i] == t[j]){
                i -= 1;
                j -= 1;
            }else{
                break;
            }
        }
        
        return (i == -1 && j == -1);
    }
};