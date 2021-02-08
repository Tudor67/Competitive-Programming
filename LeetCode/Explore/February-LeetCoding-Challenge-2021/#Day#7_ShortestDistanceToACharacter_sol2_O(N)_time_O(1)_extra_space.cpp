class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int N = s.length();
        const int INF = 1e8;
        vector<int> answer(N, INF);
        for(int isReversed = 1; isReversed >= 0; --isReversed){
            reverse(s.begin(), s.end());
            for(int pos = 0, lastPosOfC = -INF; pos < N; ++pos){
                if(s[pos] == c){
                    lastPosOfC = pos;
                }
                int answerPos = (isReversed ? N - 1 - pos : pos);
                answer[answerPos] = min(pos - lastPosOfC, answer[answerPos]);
            }
        }
        return answer;
    }
};