class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(const string& T: tokens){
            if(T == "+" || T == "-" || T == "*" || T == "/"){
                long long a = st.top();
                st.pop();
                if(T == "+"){
                    st.top() += a;
                }else if(T == "-"){
                    st.top() -= a;
                }else if(T == "*"){
                    st.top() *= a;
                }else if(T == "/"){
                    st.top() /= a;
                }
            }else{
                st.push(stoi(T));
            }
        }
        return st.top();
    }
};