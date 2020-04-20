class Solution {
private:
    string s;
    string p;
    string st;
    bool is_match;
    
    void back(int k){
        if(k == p.length()){
            is_match = is_match || (st.length() == s.length());
        }else if(k < p.length()){
            int next_k = k + 1;
            char elem = p[k];
            int elem_init_freq = 1;
            int elem_max_freq = 1;
            if(k + 1 < p.length() && p[k + 1] == '*'){
                next_k = k + 2;
                elem_init_freq = 0;
                elem_max_freq = (int)s.length() - (int)st.length();
            }
            
            for(int elem_freq = elem_max_freq; !is_match && elem_freq >= elem_init_freq; --elem_freq){
                bool ok = true;
                for(int i = (int)st.length(); i < st.length() + elem_freq; ++i){
                    if(elem != s[i] && elem != '.'){
                        ok = false;
                    }
                }
                if(ok){
                    st += string(elem_freq, elem);
                    back(next_k);
                    st.erase((int)st.length() - elem_freq);
                }
            }
        }
    }
    
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->st;
        this->is_match = false;
        
        back(0);
        
        return is_match;
    }
};