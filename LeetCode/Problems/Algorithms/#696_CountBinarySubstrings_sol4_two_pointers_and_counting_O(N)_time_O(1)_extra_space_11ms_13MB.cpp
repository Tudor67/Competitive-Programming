class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.length();

        int validSubstrings = 0;

        int i = 0;
        int prevGroupSize = 0;
        while(i < N){
            int j = i;
            while(j < N && s[i] == s[j]){
                j += 1;
            }
            int currGroupSize = j - i;
            validSubstrings += min(prevGroupSize, currGroupSize);
            prevGroupSize = currGroupSize;
            i = j;
        }

        return validSubstrings;
    }
};