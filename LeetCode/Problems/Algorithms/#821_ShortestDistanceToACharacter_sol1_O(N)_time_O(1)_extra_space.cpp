class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int N = s.length();
        const int INF = 1e8;
        
        vector<int> answer(N, INF);
        for(int pos = 0, lastPosOfC = -INF; pos < N; ++pos){
            if(s[pos] == c){
                lastPosOfC = pos;
            }
            answer[pos] = min(pos - lastPosOfC, answer[pos]);
        }
        
        for(int pos = N - 1, lastPosOfC = INF; pos >= 0; --pos){
            if(s[pos] == c){
                lastPosOfC = pos;
            }
            answer[pos] = min(lastPosOfC - pos, answer[pos]);
        }
        
        return answer;
    }
};