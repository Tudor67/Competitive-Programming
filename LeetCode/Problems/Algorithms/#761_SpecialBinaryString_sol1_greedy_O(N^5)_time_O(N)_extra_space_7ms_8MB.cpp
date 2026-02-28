class Solution {
private:
    bool isSpecialSubstring(const string& S, int startPos, int len){
        int zeros = 0;
        int ones = 0;
        for(int i = startPos; i < startPos + len; ++i){
            if(S[i] == '0'){
                zeros += 1;
            }else{
                ones += 1;
            }
            if(ones < zeros){
                return false;
            }
        }
        return (zeros == ones);
    }

public:
    string makeLargestSpecial(string s) {
        const int N = s.length();

        string prevS;
        while(prevS != s){
            prevS = s;
            for(int i = 0; i < N; ++i){
                for(int len1 = 2; i + len1 - 1 < N; len1 += 2){
                    for(int len2 = 2; i + len1 + len2 - 1 < N; len2 += 2){
                        int j = i + len1;
                        if(s.compare(i, len1, s, j, len2) < 0 &&
                           isSpecialSubstring(s, i, len1) &&
                           isSpecialSubstring(s, j, len2)){
                            rotate(s.begin() + i, s.begin() + j, s.begin() + j + len2);
                        }
                    }
                }
            }
        }

        return s;
    }
};