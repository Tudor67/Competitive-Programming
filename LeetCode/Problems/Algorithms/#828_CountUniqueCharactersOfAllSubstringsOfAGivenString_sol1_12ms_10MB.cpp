class Solution {
public:
    int uniqueLetterString(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;
        
        vector<vector<int>> positions(100);
        for(int i = 0; i < N; ++i){
            positions[s[i]].push_back(i);
        }
        
        int answer = 0;
        for(char c = 'A'; c <= 'Z'; ++c){
            for(int i = 0; i < positions[c].size(); ++i){
                int prevPos = (i == 0 ? -1 : positions[c][i - 1]);
                int currentPos = positions[c][i];
                int nextPos = (i == (int)positions[c].size() - 1 ? N : positions[c][i + 1]);
                answer += (currentPos - prevPos) * (nextPos - currentPos);
                answer %= MODULO;
            }
        }
        
        return answer;
    }
};