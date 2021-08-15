class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int N = s.length();
        const int TOTAL_ZEROS = count(s.begin(), s.end(), '0');
        const int TOTAL_ONES = count(s.begin(), s.end(), '1');
        
        // min(TOTAL_ONES, TOTAL_ZEROS): min flips to achieve "000...000" or "111...111" (i.e., [zeros] or [ones])
        int minFlips = min(TOTAL_ONES, TOTAL_ZEROS); 
        int prefZeros = 0;
        int prefOnes = 0;
        for(int i = 0; i < N; ++i){
            prefZeros += (s[i] == '0');
            prefOnes += (s[i] == '1');
            int suffZeros = TOTAL_ZEROS - prefZeros;
            // flips01: min flips to achieve "000...011..111" (i.e., [zeros][ones])
            int flips01 = prefOnes + suffZeros;
            minFlips = min(minFlips, flips01);
        }
        
        return minFlips;
    }
};