class Solution {
public:
    int numSplits(string s) {
        const int N = s.length();
        const int MAX_LETTER = 'z';
        int answer = 0;
        
        vector<int> rightCnt(MAX_LETTER + 1);
        int rightUnique = 0;
        for(char c: s){
            rightCnt[c] += 1;
            rightUnique += (rightCnt[c] == 1);
        }
        
        vector<int> leftCnt(MAX_LETTER + 1);
        int leftUnique = 0;
        for(int i = 0; i < N - 1; ++i){
            leftCnt[s[i]] += 1;
            leftUnique += (leftCnt[s[i]] == 1);
            rightCnt[s[i]] -= 1;
            rightUnique -= (rightCnt[s[i]] == 0);
            answer += (leftUnique == rightUnique);
        }
        
        return answer;
    }
};