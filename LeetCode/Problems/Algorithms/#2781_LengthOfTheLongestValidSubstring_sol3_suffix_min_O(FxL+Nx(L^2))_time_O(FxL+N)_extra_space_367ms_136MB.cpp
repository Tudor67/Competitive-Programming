class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        const int N = word.length();
        const int F = forbidden.size();
        const int MAX_FORBIDDEN_LENGTH = 10;

        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        vector<int> minForbEnd(N, N);
        int suffMinForbEnd = N;
        int res = 0;

        string s;
        for(int i = N - 1; i >= 0; --i){
            s.clear();
            for(int len = 1; len <= MAX_FORBIDDEN_LENGTH && i + len - 1 < N; ++len){
                s.push_back(word[i + len - 1]);
                if(forbiddenSet.count(s)){
                    minForbEnd[i] = i + len - 1;
                    break;
                }
            }
            suffMinForbEnd = min(suffMinForbEnd, minForbEnd[i]);
            res = max(res, suffMinForbEnd - i);
        }

        return res;
    }
};