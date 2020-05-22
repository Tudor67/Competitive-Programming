class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int N = s.length();
        const int M = p.length();
        vector<int> p_cnt(26, 0);
        for(char c: p){
            ++p_cnt[c - 'a'];
        }
        
        vector<int> cnt(26, 0);
        vector<int> answer;
        for(int i = 0; i < N; ++i){
            if(i >= M){
                --cnt[s[i - M] - 'a'];
            }
            
            ++cnt[s[i] - 'a'];

            bool match = true;
            for(int j = 0; j < p_cnt.size(); ++j){
                if(cnt[j] != p_cnt[j]){
                    match = false;
                }
            }

            if(match){
                answer.push_back(i - M + 1);
            }
        }
        
        return answer;
    }
};