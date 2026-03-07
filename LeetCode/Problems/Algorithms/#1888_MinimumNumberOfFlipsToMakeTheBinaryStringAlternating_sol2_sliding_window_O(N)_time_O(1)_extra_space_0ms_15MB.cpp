class Solution {
public:
    int minFlips(string s) {
        const int N = s.length();

        int minOps = N;
        int mismatches = 0;

        for(int i = 0; i < 2 * N - 1; ++i){
            mismatches += (s[i % N] - '0') ^ (i % 2);
            if(i >= N){
                mismatches -= (s[i - N] - '0') ^ ((i - N) % 2);
            }

            if(i >= N - 1){
                minOps = min(minOps, min(mismatches, N - mismatches));
            }
        }

        return minOps;
    }
};