class Solution {
public:
    int calculate(string s) {
        while(s.back() == ' '){
            s.pop_back();
        }
        
        const int N = s.length();
        int result = 0;
        int prevTerm = 0;
        int prevOperator = '+';
        int num = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == ' '){
                continue;
            }
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            if(!isdigit(s[i]) || i == N - 1){
                if(prevOperator == '+'){
                    result += num;
                    prevTerm = num;
                }else if (prevOperator == '-'){
                    result -= num;
                    prevTerm = -num;
                }else if(prevOperator == '*'){
                    result -= prevTerm;
                    prevTerm *= num;
                    result += prevTerm;
                }else if(prevOperator == '/'){
                    result -= prevTerm;
                    prevTerm /= num;
                    result += prevTerm;
                }
                num = 0;
            }
            if(!isdigit(s[i])){
                prevOperator = s[i];
            }
        }
        
        return result;
    }
};