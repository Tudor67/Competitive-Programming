class Solution {
public:
    char processStr(string s, long long k) {
        const int N = s.length();

        long long len = 0;
        for(char c: s){
            if(c == '*'){
                if(len >= 1){
                    len -= 1;
                }
            }else if(c == '#'){
                len += len;
            }else if(c == '%'){
                // len doesn't change
            }else{
                len += 1;
            }
        }

        if(k >= len){
            return '.';
        }

        for(int i = N - 1; i >= 0; --i){
            char c = s[i];
            if(c == '*'){
                len += 1;
            }else if(c == '#'){
                if(k >= len / 2){
                    k -= len / 2;
                }
                len /= 2;
            }else if(c == '%'){
                k = len - 1 - k;
            }else{
                if(k == len - 1){
                    return c;
                }else{
                    len -= 1;
                }
            }
        }

        return '?';
    }
};