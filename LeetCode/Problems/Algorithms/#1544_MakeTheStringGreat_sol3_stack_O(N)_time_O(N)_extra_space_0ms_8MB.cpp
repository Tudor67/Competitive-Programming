class Solution {
public:
    string makeGood(string s) {
        const int N = s.length();

        string st;
        for(char c: s){
            if(!st.empty() && tolower(st.back()) == tolower(c) && st.back() != c){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }

        return st;
    }
};