class Solution {
public:
    bool isNumber(string s) {
        const int N = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        vector<int> count(128, 0);
        for(char c: s){
            count[c] += 1;
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
            if(s[i - 1] != 'e' && (s[i] == '+' || s[i] == '-')){
                return false;
            }
        }
        
        int ePos = s.find('e');
        if(ePos != string::npos){
            int leftDigits = count_if(s.begin(), s.begin() + ePos, ::isdigit);
            int rightDigits = count_if(s.begin() + ePos + 1, s.end(), ::isdigit);
            int rightDots = ::count(s.begin() + ePos + 1, s.end(), '.');
            // wrong examples: "exxxx" or "xxxxe" or "xxxexx.x"
            if(leftDigits == 0 || rightDigits == 0 || rightDots >= 1){
                return false;
            }
        }
        
        return true;
    }
};