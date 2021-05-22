class Solution {
public:
    bool isNumber(string s) {
        const int N = s.length();
        
        vector<int> count(128, 0);
        for(char c: s){
            count[tolower(c)] += 1;
        }
        
        // wrong examples: no digits; some letters != 'e'; too many 'e' or '+' or '-' or '.'
        int digits = accumulate(count.begin() + '0', count.begin() + '9' + 1, 0);
        int letters = accumulate(count.begin() + 'a', count.begin() + 'z' + 1, 0);
        if(digits == 0 || letters - count['e'] >= 1 || count['e'] >= 2 ||
           count['.'] >= 2 || count['+'] >= 3 || count['-'] >= 3){
            return false;
        }
        
        // wrong examples: "xxx+-xxx" or "xxx-+xxx"
        //                  (consecutive '+' and '-', or alternating '+' and '-')
        for(int i = 0; i < N - 1; ++i){
            if((s[i] == '+' && s[i + 1] == '+') || (s[i] == '-' && s[i + 1] == '-') ||
               (s[i] == '+' && s[i + 1] == '-') || (s[i] == '-' && s[i + 1] == '+')){
                return false;
            }
        }
        
        // wrong examples: "xxx+xxxx" or "xxx-xxxx"
        //                 (when '+' or '-' is not preceded by 'e', exception for the first pos)
        for(int i = 1; i < N; ++i){
            if(tolower(s[i - 1]) != 'e' && (s[i] == '+' || s[i] == '-')){
                return false;
            }
        }
        
        int ePos = -1;
        for(int i = 0; i < N; ++i){
            if(tolower(s[i]) == 'e'){
                ePos = i;
            }
        }
        
        if(ePos >= 0){
            int leftDigits = 0;
            for(int i = 0; i < ePos; ++i){
                if(isdigit(s[i])){
                    leftDigits += 1;
                }
            }

            int rightDigits = 0;
            int rightDots = 0;
            for(int i = ePos + 1; i < N; ++i){
                if(isdigit(s[i])){
                    rightDigits += 1;
                }else if(s[i] == '.'){
                    rightDots += 1;
                }
            }
            
            // wrong examples: "exxxx" or "xxxxe" or "xxxexx.x"
            if(leftDigits == 0 || rightDigits == 0 || rightDots >= 1){
                return false;
            }
        }
        
        return true;
    }
};