class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(char c: s){
            if((!st.empty() && st.top() == 'A' && c == 'B') ||
               (!st.empty() && st.top() == 'C' && c == 'D')){
                st.pop();
            }else{
                st.push(c);
            }
        }

        return st.size();
    }
};