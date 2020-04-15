class Solution {
private:
    void apply_backspace(string& s){
        string st;
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(s[i]);
            }
        }
        
        s = st;
    }
    
public:
    bool backspaceCompare(string S, string T) {
        apply_backspace(S);
        apply_backspace(T);
        return (S == T);
    }
};