class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        for(char c: s){
            st.push_back(c);
            if(st.length() >= part.length() && equal(st.end() - part.length(), st.end(), part.begin())){
                st.erase(st.end() - part.length(), st.end());
            }
        }
        return st;
    }
};