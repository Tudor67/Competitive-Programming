class Solution {
public:
    int minLength(string s) {
        string st;
        for(char c: s){
            if(!st.empty() && ((st.back() == 'A' && c == 'B') || (st.back() == 'C' && c == 'D'))){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
        return st.length();
    }
};