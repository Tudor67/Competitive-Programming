class Solution {
public:
    int calculate(string s) {
        const int N = s.length();
        
        int answer = 0;
        int prevNum = 0;
        int curNum = 0;
        char prevOperation = '+';
        for(int i = 0; i <= N - 1; ++i){
            if(isdigit(s[i])){
                curNum = 10 * curNum + (s[i] - '0');
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == N - 1){
                if(prevOperation == '*'){
                    curNum = prevNum * curNum;
                }else if(prevOperation == '/'){
                    curNum = prevNum / curNum;
                }else if(prevOperation == '-'){
                    curNum = -curNum;
                }
                prevNum = curNum;
                curNum = 0;
                prevOperation = s[i];
                if(s[i] != '*' && s[i] != '/'){
                    answer += prevNum;
                }
            }
        }
        
        return answer;
    }
};