class Solution {
public:
    string makeFancyString(string s) {
        string st;
        for(char c: s){
            int n = st.size();
            if(n >= 2 && st[n - 2] == c && st[n - 1] == c){
                continue;
            }else{
                st += c;
            }
        }
        return st;
    }
};