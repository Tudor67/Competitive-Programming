class Solution {
private:
    void applyOps(string& s){
        int len = 0;
        for(char c: s){
            if(c == '#'){
                len = max(len - 1, 0);
            }else{
                len += 1;
                s[len - 1] = c;
            }
        }
        s.resize(len);
    }

public:
    bool backspaceCompare(string s, string t) {
        applyOps(s);
        applyOps(t);
        return (s == t);
    }
};