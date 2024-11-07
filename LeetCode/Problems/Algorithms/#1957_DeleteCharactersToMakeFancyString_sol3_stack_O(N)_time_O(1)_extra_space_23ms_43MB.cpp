class Solution {
public:
    string makeFancyString(string s) {
        string st;
        for(char c: s){
            int stSize = st.size();
            if(stSize >= 2 && st[stSize - 2] == c && st[stSize - 1] == c){
                continue;
            }else{
                st.push_back(c);
            }
        }
        return st;
    }
};