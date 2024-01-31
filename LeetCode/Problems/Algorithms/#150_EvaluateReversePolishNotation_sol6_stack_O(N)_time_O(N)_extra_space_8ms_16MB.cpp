class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        const int N = tokens.size();
        static const unordered_set<string> OPERATORS_SET = {"+", "-", "*", "/"};

        stack<int> st;
        for(const string& T: tokens){
            int num = 0;
            if(OPERATORS_SET.count(T)){
                num = st.top();
                st.pop();
            }
            
            if(T == "+"){
                st.top() += num;
            }else if(T == "-"){
                st.top() -= num;
            }else if(T == "*"){
                st.top() *= num;
            }else if(T == "/"){
                st.top() /= num;
            }else{
                st.push(stoi(T));
            }
        }

        return st.top();
    }
};