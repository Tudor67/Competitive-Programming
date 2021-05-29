class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& TOKEN: tokens){
            if(TOKEN == "+" || TOKEN == "-" || TOKEN == "*" || TOKEN == "/"){
                int num3 = 0;
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if(TOKEN == "+"){
                    num3 = num1 + num2;
                }else if(TOKEN == "-"){
                    num3 = num1 - num2;
                }else if(TOKEN == "*"){
                    num3 = num1 * num2;
                }else if(TOKEN == "/"){
                    num3 = num1 / num2;
                }
                st.push(num3);
            }else{
                st.push(stoi(TOKEN));
            }
        }
        return st.top();
    }
};