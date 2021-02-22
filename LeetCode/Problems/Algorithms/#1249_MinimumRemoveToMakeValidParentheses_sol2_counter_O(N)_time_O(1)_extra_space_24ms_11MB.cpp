class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Step 1: remove bad ')' by moving from left to right
        string t;
        int openedPar = 0;
        for(int i = 0; i < (int)s.length(); ++i){
            if(s[i] == '('){
                openedPar += 1;
                t += s[i];
            }else if(s[i] == ')'){
                if(openedPar > 0){
                    openedPar -= 1;
                    t += s[i];
                }
            }else{
                t += s[i];
            }
        }
        
        // Step 2: remove bad '(' by moving from right to left
        s = t;
        t = "";
        for(int i = (int)s.length() - 1; i >= 0; --i){
            if(s[i] == '(' && openedPar > 0){
                openedPar -= 1;
            }else{
                t += s[i];
            }
        }
        
        // Step 3: reverse t
        reverse(t.begin(), t.end());
        
        return t;
    }
};