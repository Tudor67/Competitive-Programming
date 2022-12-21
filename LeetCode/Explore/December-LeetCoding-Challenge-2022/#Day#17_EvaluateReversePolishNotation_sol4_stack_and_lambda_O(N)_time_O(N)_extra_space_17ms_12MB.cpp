class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long long(long long, long long)>> f = {
            {"+", [](long long a, long long b){ return a + b; }},
            {"-", [](long long a, long long b){ return a - b; }},
            {"*", [](long long a, long long b){ return a * b; }},
            {"/", [](long long a, long long b){ return a / b; }}
        };

        stack<long long> st;
        for(const string& T: tokens){
            if(isdigit(T.back())){
                st.push(stoi(T));
            }else{
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                st.push(f[T](a, b));
            }
        }

        return st.top();
    }
};