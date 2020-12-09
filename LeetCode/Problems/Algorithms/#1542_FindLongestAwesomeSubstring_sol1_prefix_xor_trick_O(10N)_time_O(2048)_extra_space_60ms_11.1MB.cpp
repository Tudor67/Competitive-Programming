class Solution {
public:
    int longestAwesome(string s) {
        const int INF = 1e9;
        const int MAX_MASK = (1 << 11);
        vector<int> firstPos(MAX_MASK, INF);
        firstPos[0] = -1;
        
        int answer = 0;
        int curMask = 0;
        for(int i = 0; i < s.length(); ++i){
            int digit = s[i] - '0';
            curMask ^= (1 << digit);
            if(firstPos[curMask] == INF){
                firstPos[curMask] = i;
            }
            answer = max(i - firstPos[curMask], answer);
            for(int bit = 0; bit <= 9; ++bit){
                int prevMask = curMask ^ (1 << bit);
                if(firstPos[prevMask] != INF){
                    answer = max(i - firstPos[prevMask], answer);
                }
            }
        }
        
        return answer;
    }
};