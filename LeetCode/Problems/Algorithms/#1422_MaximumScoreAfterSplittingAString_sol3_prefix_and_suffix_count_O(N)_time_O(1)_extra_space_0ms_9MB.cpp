class Solution {
public:
    int maxScore(string s) {
        const int N = s.length();

        int maximumScore = 0;
        int leftZeros = 0;
        int rightOnes = count(s.begin(), s.end(), '1');
        for(int i = 0; i + 1 < N; ++i){
            leftZeros += (int)(s[i] == '0');
            rightOnes -= (int)(s[i] == '1');
            maximumScore = max(maximumScore, leftZeros + rightOnes);
        }

        return maximumScore;
    }
};