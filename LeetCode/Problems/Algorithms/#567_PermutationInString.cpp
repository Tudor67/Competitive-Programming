class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N = s1.length();
        const int M = s2.length();
        
        vector<int> s1_cnt(26, 0);
        for(char c: s1){
            ++s1_cnt[c - 'a'];
        }
        
        bool is_included = false;
        vector<int> s2_cnt(26, 0);
        for(int i = 0; !is_included && i < M; ++i){
            if(i >= N){
                --s2_cnt[s2[i - N] - 'a'];
            }
            ++s2_cnt[s2[i] - 'a'];
            
            is_included = true;
            for(int j = 0; j < 26; ++j){
                if(s1_cnt[j] != s2_cnt[j]){
                    is_included = false;
                }
            }
        }
        
        return is_included;
    }
};