class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.length();
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                int min_left_op = 0;
                for(int j = 0; j <= i; ++j){
                    if(s[j] == '('){
                        ++min_left_op;
                    }else if(min_left_op > 0){
                        --min_left_op;
                    }
                }
                
                int max_right_cl = 0;
                for(int j = i + 1; j < n; ++j){
                    max_right_cl += (s[j] != '(');
                }
                
                if(min_left_op > max_right_cl){
                    return false;
                }
            }else if(s[i] == ')'){
                int max_left_op = 0;
                for(int j = 0; j < i; ++j){
                    max_left_op += (s[j] != ')');
                }
                
                int min_right_cl = 0;
                for(int j = n - 1; j >= i; --j){
                    if(s[j] == ')'){
                        ++min_right_cl;
                    }else if(min_right_cl > 0){
                        --min_right_cl;
                    }
                }
                
                if(max_left_op < min_right_cl){
                    return false;
                }
            }
        }
        
        return true;
    }
};