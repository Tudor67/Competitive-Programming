class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(; n >= 2; --n){
            string nextS;
            int count = 1;
            for(int i = 1; i <= (int)s.length(); ++i){
                if(i < (int)s.length() && s[i] == s[i - 1]){
                    count += 1;
                }else{
                    nextS += to_string(count);
                    nextS += s[i - 1];
                    count = 1;
                }
            }
            s = nextS;
        }
        return s;
    }
};