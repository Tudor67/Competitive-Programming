class Solution {
private:
    bool match(char a, char b){
        return (a == '(' && b == ')') ||
               (a == '[' && b == ']') ||
               (a == '{' && b == '}');
    }
    
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(st.empty() || !match(st.top(), c)){
                st.push(c);
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};