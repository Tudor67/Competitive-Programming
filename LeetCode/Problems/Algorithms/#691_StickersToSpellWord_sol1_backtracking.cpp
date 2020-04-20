class Solution {
private:
    int n;
    vector<vector<int>> stickers_cnt;
    vector<int> target_cnt;
    vector<int> cnt;
    vector<bool> good_candidate_at;
    
    void count_chars_and_update_cnt(const vector<string>& stickers, vector<vector<int>>& cnt){
        for(int i = 0; i < stickers.size(); ++i){
            for(const char& c: stickers[i]){
                ++cnt[i][c - 'a'];
            }
        }
    }
    
    void count_chars_and_update_cnt(const string& sticker, vector<int>& cnt){
        for(const char& c: sticker){
            ++cnt[c - 'a'];
        }
    }
    
    void update_good_candidates(){
        for(int cur_sticker_id = 0; cur_sticker_id < stickers_cnt.size(); ++cur_sticker_id){
            bool match_with_target = 0;
            for(int j = 0; j < target_cnt.size(); ++j){
                if(stickers_cnt[cur_sticker_id][j] == target_cnt[j]){
                    match_with_target = 1;
                }
            }
            
            bool is_dominated = 0;
            for(int i = 0; i < stickers_cnt.size(); ++i){
                if(i != cur_sticker_id && good_candidate_at[i]){
                    int k1 = 0;
                    int k2 = 0;
                    for(int j = 0; j < stickers_cnt[i].size(); ++j){
                        if(target_cnt[j] > 0){
                            k1 += 1;
                            k2 += (stickers_cnt[cur_sticker_id][j] <= stickers_cnt[i][j]);
                        }
                    }
                    is_dominated = is_dominated || (k1 == k2);
                }
            }
            
            good_candidate_at[cur_sticker_id] = match_with_target && !is_dominated;
        }
    }
    
    int get_needed_stickers(const int& sticker_id){
        int x = 0;
        for(int i = 0; i < cnt.size(); ++i){
            if(stickers_cnt[sticker_id][i] > 0 && target_cnt[i] > cnt[i]){
                x = max(x, (target_cnt[i] - cnt[i]) / stickers_cnt[sticker_id][i]
                            +
                           ((target_cnt[i] - cnt[i]) % stickers_cnt[sticker_id][i] > 0));
            }
        }
        return x;
    }
    
    bool is_complete(){
        for(int i = 0; i < cnt.size(); ++i){
            if(cnt[i] < target_cnt[i]){
                return 0;
            }
        }
        return 1;
    }
    
    void update_cnt(const int& sticker_id, const int& x){
        for(int i = 0; i < cnt.size(); ++i){
            cnt[i] += x * stickers_cnt[sticker_id][i];
        }
    }
    
    void back(int k, int last_pos, int& ans){
        if(is_complete()){
            ans = min(k, ans);
        }else if(k < ans){
            for(int i = last_pos + 1; i < n; ++i){
                if(good_candidate_at[i]){
                    int x = get_needed_stickers(i);
                    for(int j = x; j >= 1; --j){
                        update_cnt(i, j);
                        back(k + j, i, ans);
                        update_cnt(i, -j);
                    }
                }
            }
        }
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
        this->n = stickers.size();
        this->stickers_cnt.resize(n, vector<int>(26, 0));
        this->target_cnt.resize(26, 0);
        this->cnt.resize(26, 0);
        this->good_candidate_at.resize(n, 1);
        
        count_chars_and_update_cnt(stickers, stickers_cnt);
        count_chars_and_update_cnt(target, target_cnt);
        update_good_candidates();
        
        int ans = target.size() + 1;
        back(0, -1, ans);
        
        if(ans == target.size() + 1){
            ans = -1;
        }
        
        return ans;
    }
};