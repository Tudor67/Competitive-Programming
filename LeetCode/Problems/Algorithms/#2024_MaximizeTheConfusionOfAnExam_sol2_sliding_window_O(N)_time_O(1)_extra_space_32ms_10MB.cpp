class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        const int N = answerKey.length();

        int res = 0;
        for(char targetChar: {'T', 'F'}){
            int l = 0;
            int badChars = 0;
            for(int r = 0; r < N; ++r){
                badChars += (int)(answerKey[r] != targetChar);
                while(badChars > k){
                    badChars -= (int)(answerKey[l] != targetChar);
                    l += 1;
                }
                res = max(res, r - l + 1);
            }
        }
        
        return res;
    }
};