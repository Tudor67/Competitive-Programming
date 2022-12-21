class Solution {
private:
    long long f(const string& OPERATOR, long long a, long long b){
        if(OPERATOR == "+") return a + b;
        if(OPERATOR == "-") return a - b;
        if(OPERATOR == "*") return a * b;
        if(OPERATOR == "/") return a / b;
        return LLONG_MIN;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(const string& T: tokens){
            if(isdigit(T.back())){
                st.push(stoi(T));
            }else{
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                st.push(f(T, a, b));
            }
        }
        return st.top();
    }
};