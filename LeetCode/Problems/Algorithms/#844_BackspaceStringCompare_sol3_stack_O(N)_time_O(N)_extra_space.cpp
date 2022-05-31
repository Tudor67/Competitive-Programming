class Solution {
private:
    string getFinalString(const string& S){
        string st;
        for(char c: S){
            if(c == '#'){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(c);
            }
        }
        return st;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        return (getFinalString(s) == getFinalString(t));
    }
};