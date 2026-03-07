class Solution {
public:
    bool checkOnesSegment(string s) {
        const int N = s.length();

        for(int i = 0; i + 1 < N; ++i){
            if(s[i] == '0' && s[i + 1] == '1'){
                return false;
            }
        }

        return true;
    }
};