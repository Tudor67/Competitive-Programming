class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.length();
        vector<int> min_left_op(n + 1, 0);  // min number of opened parenthesis in range [0 .. i]
        vector<int> max_left_op(n + 1, 0);  // max number of opened parenthesis in range [0 .. i]
        vector<int> min_right_cl(n + 1, 0); // min number of closed parenthesis in range [i .. n - 1]
        vector<int> max_right_cl(n + 1, 0); // max number of closed parenthesis in range [i .. n - 1]
        
        for(int i = 0; i < n; ++i){
            if(i > 0){
                min_left_op[i] = min_left_op[i - 1];
                max_left_op[i] = max_left_op[i - 1];
            }
            
            if(s[i] == '('){
                ++min_left_op[i];
            }else if(min_left_op[i] > 0){
                --min_left_op[i];
            }
            
            if(s[i] == '(' || s[i] == '*'){
                ++max_left_op[i];
            }
        }
        
        for(int i = n - 1; i >= 0; --i){
            min_right_cl[i] = min_right_cl[i + 1];
            max_right_cl[i] = max_right_cl[i + 1];
            
            if(s[i] == ')'){
                ++min_right_cl[i];
            }else if(min_right_cl[i] > 0){
                --min_right_cl[i];
            }
            
            if(s[i] == ')' || s[i] == '*'){
                ++max_right_cl[i];
            }
        }
        
        for(int i = 0; i < n; ++i){
            bool stop_cond1 = (s[i] == '(' && min_left_op[i] > max_right_cl[i]);
            bool stop_cond2 = (s[i] == ')' && max_left_op[i] < min_right_cl[i]);
            if(stop_cond1 || stop_cond2){
                return false;
            }
        }
        
        return true;
    }
};