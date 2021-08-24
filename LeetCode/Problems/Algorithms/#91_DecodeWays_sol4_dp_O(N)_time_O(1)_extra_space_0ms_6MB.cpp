class Solution {
private:
    bool isValid(char c){
        return (isdigit(c) && c >= '1');
    }
    
    bool isValid(char c1, char c2){
        return (isdigit(c1) && isdigit(c2) && !(c1 == '0' || c1 >= '3' || (c1 == '2' && c2 >= '7')));
    }
    
public:
    int numDecodings(string s) {
        const int N = s.length();
        // At step i:
        // decodings: number of ways to decode s[0 .. i]
        // decodings1: number of ways to decode s[0 .. i - 1]
        // decodings2: number of ways to decode s[0 .. i - 2]
        int decodings = isValid(s[0]);
        int decodings1 = isValid(s[0]);
        int decodings2 = 1;
        for(int i = 1; i < N; ++i){
            decodings = 0;
            decodings += isValid(s[i]) * decodings1;
            decodings += isValid(s[i - 1], s[i]) * decodings2;
            decodings2 = decodings1;
            decodings1 = decodings;
        }
        return decodings;
    }
};