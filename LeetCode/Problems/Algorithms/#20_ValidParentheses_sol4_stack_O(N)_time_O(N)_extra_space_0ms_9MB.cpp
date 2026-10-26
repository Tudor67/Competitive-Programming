class Solution {
private:
    bool isValidPair(char a, char b){
        return (a == '(' && b == ')') ||
               (a == '[' && b == ']') ||
               (a == '{' && b == '}');
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for(char c: s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else if(!st.empty() && isValidPair(st.top(), c)){
                st.pop();
            }else{
                return false;
            }
        }

        return st.empty();
    }
};