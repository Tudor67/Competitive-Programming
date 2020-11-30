class Solution {
public:
    int calculate(string s) {
        const int N = s.length();
        
        stack<int> st;
        int num = 0;
        char prevOperation = '+';
        for(int i = 0; i <= N - 1; ++i){
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == N - 1){
                if(prevOperation == '*'){
                    st.top() *= num;
                }else if(prevOperation == '/'){
                    st.top() /= num;
                }else if(prevOperation == '+'){
                    st.push(num);
                }else if(prevOperation == '-'){
                    st.push(-num);
                }
                num = 0;
                prevOperation = s[i];
            }
        }
        
        int answer = 0;
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
                   
        return answer;
    }
};