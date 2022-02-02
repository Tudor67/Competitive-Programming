class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int N = s.length();
        
        // Step 1: special case (odd number of parentheses)
        if(N % 2 == 1){
            return false;
        }
        
        // Step 2: check if every prefix s[0 .. i]
        //         can be transformed to a valid parentheses string
        //         (possibly with some redundant opened parentheses)
        //         this step ensures that we don't have unpaired ')' in s
        int bal = 0;
        for(int i = 0; i < N; ++i){
            if(locked[i] == '0'){
                bal += 1;
            }else{
                if(s[i] == '('){
                    bal += 1;
                }else{
                    bal -= 1;
                }
            }
            if(bal < 0){
                return false;
            }
        }
        
        // Step 3: check if every suffix s[i .. N - 1]
        //         can be transformed to a valid parentheses string
        //         (possibly with some redundant closed parentheses)
        //         this step ensures that we don't have unpaired '(' in s
        bal = 0;
        for(int i = N - 1; i >= 0; --i){
            if(locked[i] == '0'){
                bal += 1;
            }else{
                if(s[i] == ')'){
                    bal += 1;
                }else{
                    bal -= 1;
                }
            }
            if(bal < 0){
                return false;
            }
        }
        
        return true;
    }
};