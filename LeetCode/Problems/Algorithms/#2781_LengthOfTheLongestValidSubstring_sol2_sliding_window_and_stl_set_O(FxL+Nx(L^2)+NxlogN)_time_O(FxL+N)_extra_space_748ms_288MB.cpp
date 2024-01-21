class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        const int N = word.length();
        const int F = forbidden.size();
        const int MAX_FORBIDDEN_LENGTH = 10;
        
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        vector<int> minForbEnd(N, N + 5);

        string s;
        for(int i = 0; i < N; ++i){
            s.clear();
            for(int len = 1; len <= MAX_FORBIDDEN_LENGTH && i + len - 1 < N; ++len){
                s.push_back(word[i + len - 1]);
                if(forbiddenSet.count(s)){
                    minForbEnd[i] = i + len - 1;
                    break;
                }
            }
        }

        int res = 0;
        int l = 0;
        set<pair<int, int>> sp;
        for(int r = 0; r < N; ++r){
            sp.insert({minForbEnd[r], r});
            while(!sp.empty() && sp.begin()->first <= r){
                sp.erase({minForbEnd[l], l});
                l += 1;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};