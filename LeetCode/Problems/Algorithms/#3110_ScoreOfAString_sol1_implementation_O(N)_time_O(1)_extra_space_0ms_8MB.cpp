class Solution {
public:
    int scoreOfString(string s) {
        const int N = s.length();

        int score = 0;
        for(int i = 1; i < N; ++i){
            score += abs(s[i] - s[i - 1]);
        }

        return score;
    }
};