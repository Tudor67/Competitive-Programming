class Solution {
public:
    int maxScore(string s) {
        const int N = s.length();

        int maxDiff = -N;
        int prefOnes = 0;
        int totalOnes = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '1'){
                prefOnes += 1;
                totalOnes += 1;
            }
            if(i + 1 < N){
                maxDiff = max(maxDiff, i + 1 - 2 * prefOnes);
            }
        }

        return maxDiff + totalOnes;
    }
};