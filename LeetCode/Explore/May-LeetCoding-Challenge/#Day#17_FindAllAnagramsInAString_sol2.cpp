class Solution {
private:
    void update(vector<int>& cnt, const vector<int>& p_cnt, const char& ch,
                const int& val, int& mismatch_cnt){
        int idx = ch - 'a';
        cnt[idx] += val;
        if(cnt[idx] == p_cnt[idx]){
            mismatch_cnt -= 1;
        }else{
            mismatch_cnt += (cnt[idx] == p_cnt[idx] + val);
        }
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        const int N = s.length();
        const int M = p.length();
        vector<int> answer;
        
        if(N >= M){
            vector<int> p_cnt(26, 0);
            for(char c: p){
                ++p_cnt[c - 'a'];
            }

            vector<int> cnt(26, 0);
            for(int i = 0; i < M - 1; ++i){
                ++cnt[s[i] - 'a'];
            }

            int mismatch_cnt = 0;
            for(int j = 0; j < p_cnt.size(); ++j){
                mismatch_cnt += (cnt[j] != p_cnt[j]);
            }

            for(int i = M - 1; i < N; ++i){
                if(i >= M){
                    update(cnt, p_cnt, s[i - M], -1, mismatch_cnt);
                }
                update(cnt, p_cnt, s[i], +1, mismatch_cnt);
                if(mismatch_cnt == 0){
                    answer.push_back(i - M + 1);
                }
            }
        }
        
        return answer;
    }
};