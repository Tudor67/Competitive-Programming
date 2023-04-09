class Solution {
public:
    int partitionString(string s) {
        const int N = s.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        int res = 1;
        int visMask = 0;
        for(char c: s){
            int bit = c - FIRST_CHAR;
            if((visMask >> bit) & 1){
                res += 1;
                visMask = 0;
            }
            visMask |= (1 << bit);
        }

        return res;
    }
};