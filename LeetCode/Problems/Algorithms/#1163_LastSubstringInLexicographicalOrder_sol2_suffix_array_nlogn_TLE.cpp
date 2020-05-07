class Solution {
private:
    struct Tuple{
        int first;
        int second;
        int i;
    };
    
    vector<int> cnt;
    vector<Tuple> out;
    
    void count_sort(vector<Tuple>& v,
                    const int& start_pos, const int& end_pos,
                    const int& idx, const int& p){
        if(end_pos > start_pos){
            cnt.resize(10);
            fill(cnt.begin(), cnt.end(), 0);
            
            for(int i = start_pos; i <= end_pos; ++i){
                int val = (idx == 0 ? v[i].first : v[i].second);
                ++cnt[(val / p) % 10];
            }
            
            for(int i = 1; i < cnt.size(); ++i){
                cnt[i] += cnt[i - 1];
            }
            
            out.resize(end_pos - start_pos + 1);
            for(int i = end_pos; i >= start_pos; --i){
                int val = (idx == 0 ? v[i].first : v[i].second);
                out[cnt[(val / p) % 10] - 1] = v[i];
                cnt[(val / p) % 10] -= 1;
            }
            
            for(int i = start_pos; i <= end_pos; ++i){
                v[i] = out[i - start_pos];
            }
        }
    }
    
    void radix_sort(vector<Tuple>& v, const int& max_val){        
        for(int p = 1; p <= max_val; p *= 10){
            count_sort(v, 0, (int)v.size() - 1, 0, p);
        }
        
        for(int i = 0, start_pos = 0; i < v.size(); ++i){
            bool cond1 = (i == (int)v.size() - 1);
            bool cond2 = (i + 1 < v.size() && v[i].first != v[i + 1].first);
            if(cond1 || cond2){
                for(int p = 1; p <= max_val; p *= 10){
                    count_sort(v, start_pos, i, 1, p);
                }
                start_pos = i + 1;
            }
        }
    }
    
public:
    string lastSubstring(string s) {
        const int N = s.length();
        
        char min_char = s[0];
        char max_char = s[0];
        int pos_of_first_max_char = 0;
        int max_char_cnt = 1;
        for(int i = 1; i < N; ++i){
            if(s[i] == max_char){
                ++max_char_cnt;
            }else if(s[i] > max_char){
                max_char = s[i];
                pos_of_first_max_char = i;
                ++max_char_cnt;
            }
            min_char = min(s[i], min_char);
        }
        
        if(max_char_cnt == 1 || max_char_cnt == N){
            return s.substr(pos_of_first_max_char);
        }
        
        // Suffix Arrays: O(N*log(N))
        // init
        vector<Tuple> l(N);
        vector<int> suffix_rank(N + 1, 0);
        for(int i = 0; i < N; ++i){
            suffix_rank[i] = s[i] - min_char + 1;
        }
        
        int prev_step = 0;
        int cur_step = 1;
        int max_val = 256;
        for(int p = 1; p <= 2 * N; p *= 2){
            // update l
            for(int i = 0; i < N; ++i){
                l[i].first = suffix_rank[i];
                l[i].second = suffix_rank[min(i + p / 2, N)];
                l[i].i = i;
            }
            
            // sort l
            radix_sort(l, max_val);
            
            // update pos
            pair<int, int> p1;
            pair<int, int> p2;
            for(int i = 0, p = 1; i < N; ++i){
                if(i > 0){
                    p1.first = l[i - 1].first;
                    p1.second = l[i - 1].second;
                    p2.first = l[i].first;
                    p2.second = l[i].second;
                    p += (p1 != p2);
                }
                suffix_rank[l[i].i] = p;
                max_val = max(p, max_val);
            }
        }
        
        int start_pos = 0;
        for(int i = 0; i < N; ++i){
            if(suffix_rank[start_pos] < suffix_rank[i]){
                start_pos = i;
            }
        }
        
        return s.substr(start_pos);
    }
};