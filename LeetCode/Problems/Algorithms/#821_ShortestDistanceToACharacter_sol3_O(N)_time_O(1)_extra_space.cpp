class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int N = s.length();
        vector<int> answer(N, INT_MAX);
        for(int i = 0; i < N; ++i){
            if(s[i] == c){
                for(int j = i; j >= 0 && answer[j] > i - j; --j){
                    answer[j] = i - j;
                }
                for(int j = i + 1; j < N && s[j] != c && answer[j] > j - i; ++j){
                    answer[j] = j - i;
                }
            }
        }
        return answer;
    }
};