class Solution {
private:
    void apply_backspace(string& s){
        for(int i = -1, j = 0; j < s.length(); ++j){
            if(s[j] == '#'){
                s[j] = '.';
                if(i >= 0){
                    s[i--] = '.';
                }
            }else{
                s[++i] = s[j];
                if(i < j){
                    s[j] = '.';
                }
            }
        }
        
        for(int i = (int)s.length() - 1; i >= 0; --i){
            if(s[i] == '.'){
                s.pop_back();
            }
        }
    }
    
public:
    bool backspaceCompare(string S, string T) {
        apply_backspace(S);
        apply_backspace(T);
        return (S == T);
    }
};