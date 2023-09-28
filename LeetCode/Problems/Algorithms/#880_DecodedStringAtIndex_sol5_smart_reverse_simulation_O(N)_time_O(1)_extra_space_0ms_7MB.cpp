class Solution {
public:
    string decodeAtIndex(string s, int k) {
        const int N = s.length();

        long long tapeLen = 0;
        for(char c: s){
            if(isdigit(c)){
                tapeLen *= (c - '0');
            }else{
                tapeLen += 1;
            }
        }

        for(int i = N - 1; i >= 0; --i){
            k %= tapeLen;
            if(k == 0 && !isdigit(s[i])){
                return string(1, s[i]);
            }
            if(isdigit(s[i])){
                tapeLen /= (s[i] - '0');
            }else{
                tapeLen -= 1;
            }
        }

        return "";
    }
};