class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;

        for(char c: s){
            if(c == ')'){
                bool hasTrue = false;
                bool hasFalse = false;
                while(!st.empty() && st.top() != '('){
                    hasTrue = hasTrue || (st.top() == 't');
                    hasFalse = hasFalse || (st.top() == 'f');
                    st.pop();
                }
                st.pop();

                char currOperator = st.top();
                st.pop();

                bool res = true;
                if(currOperator == '!'){
                    res = hasFalse;
                }else if(currOperator == '&'){
                    res = !hasFalse;
                }else{
                    res = hasTrue;
                }

                st.push(res ? 't' : 'f');
            }else{
                st.push(c);
            }
        }

        return (st.top() == 't');
    }
};