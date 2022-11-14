class Solution {
public:
    string makeGood(string s) {
        const int N = s.length();
        
        int len = 0;
        for(char c: s){
            if(len >= 1 && tolower(s[len - 1]) == tolower(c) && islower(s[len - 1]) != islower(c)){
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