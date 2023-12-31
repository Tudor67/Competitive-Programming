class Solution {
public:
    int maxScore(string s) {
        const int N = s.length();

        // score[i] = prefZeros[i] + suffOnes[i + 1]
        //          = prefZeros[i] + TOTAL_ONES - prefOnes[i]
        // TOTAL_ONES is a constant
        // max(score[i]) = max(prefZeros[i] + TOTAL_ONES - prefOnes[i])
        //               = max(prefZeros[i] - prefOnes[i]) + TOTAL_ONES
        int maxDiff = -N;
        int zeros = 0;
        int ones = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(s[i] == '0'){
                zeros += 1;
            }else{
                ones += 1;
            }
            maxDiff = max(maxDiff, zeros - ones);
        }

        if(s[N - 1] == '1'){
            ones += 1;
        }

        return maxDiff + ones;
    }
};