class Solution {
public:
    string removeDuplicates(string s) {
        int len = 0;
        for(char c: s){
            if(len >= 1 && s[len - 1] == c){
                len -= 1;
            }else{
                s[len] = c;
                len += 1;
            }
        }
        s.resize(len);
        return s;
    }
};