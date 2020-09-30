class Solution {
private:
    vector<int> count_chars(const string& S){
        vector<int> cnt(256, 0);
        for(int c: S){
            cnt[c] += 1;
        }
        return cnt;
    }
    
public:
    string minWindow(string s, string t) {
        string answer;
        
        vector<int> s_cnt(count_chars(s));
        vector<int> t_cnt(count_chars(t));

        bool contains = true;
        for(int c = 0; c < s_cnt.size(); ++c){
            if(s_cnt[c] < t_cnt[c]){
                contains = false;
            }
        }

        if(contains){
            int p1 = 0;
            for(int i = 0; i < s.length() && s_cnt[s[i]] - 1 >= t_cnt[s[i]]; ++i){
                s_cnt[s[i]] -= 1;
                p1 = i + 1;
            }

            int p2 = (int)s.length() - 1;
            for(int i = (int)s.length() - 1; i > p1 && s_cnt[s[i]] - 1 >= t_cnt[s[i]]; --i){
                s_cnt[s[i]] -= 1;
                p2 = i - 1;
            }
            
            int best_p1 = p1;
            int best_p2 = p2;
            while(p1 > 0){
                for(p1 = p1 - 1; p1 >= 0 && s[p1] != s[p2]; --p1){
                    s_cnt[s[p1]] += 1;
                }
                
                for(p2 = p2 - 1; p2 > p1 && s_cnt[s[p2]] - 1 >= t_cnt[s[p2]]; --p2){
                    s_cnt[s[p2]] -=1;
                }

                if(p1 >= 0 && p2 - p1 < best_p2 - best_p1){
                    best_p1 = p1;
                    best_p2 = p2;
                }
            }
            
            answer = s.substr(best_p1, best_p2 - best_p1 + 1);
        }
        
        return answer;
    }
};