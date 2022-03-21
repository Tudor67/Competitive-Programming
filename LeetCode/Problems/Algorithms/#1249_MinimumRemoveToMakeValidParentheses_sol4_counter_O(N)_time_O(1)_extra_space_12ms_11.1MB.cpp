class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.length();
        
        int openedPar = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                openedPar += 1;
            }else if(s[i] == ')'){
                if(openedPar > 0){
                    openedPar -= 1;
                }else{
                    s[i] = '#';
                }
            }
        }
        
        for(int i = N - 1; i >= 0; --i){
            if(s[i] == '(' && openedPar > 0){
                s[i] = '#';
                openedPar -= 1;
            }
        }
        
        string res;
        for(char c: s){
            if(c != '#'){
                res += c;
            }
        }
        
        return res;
    }
};