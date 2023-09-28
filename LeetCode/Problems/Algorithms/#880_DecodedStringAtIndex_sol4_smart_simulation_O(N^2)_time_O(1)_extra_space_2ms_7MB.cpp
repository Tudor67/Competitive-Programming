class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long prevTapeLen = 0;
        long long tapeLen = 0;
        char tapeLetter = 'z' + 1;

        while(true){
            for(char c: s){
                prevTapeLen = tapeLen;

                if(isdigit(c)){
                    tapeLen *= (c - '0');
                }else{
                    tapeLetter = c;
                    tapeLen += 1;
                }

                if(tapeLen == k){
                    return string(1, tapeLetter);
                }else if(tapeLen > k){
                    k = (k - 1) % prevTapeLen + 1;
                    tapeLen = 0;
                    break;
                }
            }
        }

        return "";
    }
};