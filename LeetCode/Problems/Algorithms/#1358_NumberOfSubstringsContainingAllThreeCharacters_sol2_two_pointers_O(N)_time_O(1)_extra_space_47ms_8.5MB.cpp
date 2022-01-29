class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();
        
        int aPos = 0;
        int bPos = 0;
        int cPos = 0;
        int answer = 0;
        for(int i = 0; i < N; ++i){
            aPos = find(s.begin() + max(i, aPos), s.end(), 'a') - s.begin();
            bPos = find(s.begin() + max(i, bPos), s.end(), 'b') - s.begin();
            cPos = find(s.begin() + max(i, cPos), s.end(), 'c') - s.begin();
            answer += (N - max({aPos, bPos, cPos}));
        }
        
        return answer;
    }
};