class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int N = s.length();
        // At step i:
        //    minFlips0: minimum number of flips to make s[0 .. i] monotone increasing and ending in '0';
        //    minFlips1: minimum number of flips to make s[0 .. i] monotone increasing and ending in '1';
        int minFlips0 = 0;
        int minFlips1 = 0;
        for(int i = 0; i < N; ++i){
            int flipTo0 = (s[i] != '0');
            int flipTo1 = (s[i] != '1');
            minFlips1 = min(minFlips0, minFlips1) + flipTo1;
            minFlips0 = minFlips0 + flipTo0;
        }
        return min(minFlips0, minFlips1);
    }
};