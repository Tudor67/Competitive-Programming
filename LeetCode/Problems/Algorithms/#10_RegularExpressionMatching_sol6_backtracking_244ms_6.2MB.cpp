class Solution {
private:
    string s;
    string p;
    string st;
    int st_len;
    bool is_match;
    
    void back(int k){
        if(k == p.length()){
            is_match = is_match || (st_len == s.length());
        }else if(k < p.length()){
            int next_k = k + 1;
            char elem = p[k];
            int elem_init_freq = 1;
            int elem_max_freq = 1;
            if(k + 1 < p.length() && p[k + 1] == '*'){
                next_k = k + 2;
                elem_init_freq = 0;
                elem_max_freq = (int)s.length() - st_len;
            }
            
            for(int elem_freq = elem_init_freq; !is_match && elem_freq <= elem_max_freq; ++elem_freq){
                bool ok = true;
                for(int i = st_len; i < st_len + elem_freq; ++i){
                    if(elem != s[i] && elem != '.'){
                        ok = false;
                        elem_max_freq = -1; // no reason to try frequencies >= current elem_freq
                    }
                }
                if(ok){
                    fill(st.begin() + st_len, st.begin() + st_len + elem_freq, elem);
                    st_len += elem_freq;
                    back(next_k);
                    st_len -= elem_freq;
                }
            }
        }
    }
    
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->st.resize(s.length() + 5);
        this->st_len = 0;
        this->is_match = false;
        
        back(0);
        
        return is_match;
    }
};