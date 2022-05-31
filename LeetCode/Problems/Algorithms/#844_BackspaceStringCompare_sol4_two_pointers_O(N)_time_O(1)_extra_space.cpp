class Solution {
private:
    void updateString(string& s){
        int i = -1;
        for(char c: s){
            if(c == '#'){
                i = max(i - 1, -1);
            }else{
                s[++i] = c;
            }
        }
        s.resize(i + 1);
    }
    
public:
    bool backspaceCompare(string s, string t) {
        updateString(s);
        updateString(t);
        return (s == t);
    }
};