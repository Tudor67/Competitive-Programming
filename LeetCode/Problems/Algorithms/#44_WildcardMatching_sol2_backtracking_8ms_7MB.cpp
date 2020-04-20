class Solution {
private:
    string s;
    string p;
    bool is_match;
    
    bool prefix_match(){
        for(int i = 0; i < min(s.length(), p.length()); ++i){
            if(s[i] != p[i]){
                return (p[i] == '*' || p[i] == '?');
            }
        }
        return true;
    }
    
    bool suffix_match(){
        for(int i = (int)s.length() - 1, j = (int)p.length() - 1; i >= 0 && j >= 0; --i, --j){
            if(s[i] != p[j]){
                return (p[j] == '*' || p[j] == '?');
            }
        }
        return true;
    }
    
    bool s_contains_all_letter_sequences_from_p(){
        int pos = 0;
        string seq = "";
        
        for(char c: p){
            if(c != '*' && c != '?'){
                seq += c;
            }else{
                if(!seq.empty()){
                    pos = s.find(seq, pos);
                    if(pos == string::npos){
                        return false;
                    }
                    pos += seq.length();
                    seq = "";
                }
            }
        }

        if(!seq.empty()){
            pos = s.find(seq, pos);
            if(pos == string::npos){
                return false;
            }
        }
        
        return true;
    }
    
    void remove_consecutive_wildcards(){
        string st;
        for(int i = 0; i < p.length(); ++i){
            if(p[i] == '*'){
                if(!st.empty() && st.back() == '*'){
                    st.pop_back();
                }
            }
            st.push_back(p[i]);
        }
        p = st;
    }
    
    static bool is_letter(char c){
        return (c != '?' && c != '*');
    }
    
    void back(int s_idx, int p_idx){
        if(p_idx == p.length()){
            is_match = is_match || (s_idx == s.length());
        }else{
            if(s[s_idx] == p[p_idx] || p[p_idx] == '?' || p[p_idx] == '*'){
                char elem = p[p_idx];
                int elem_min_freq = 1;
                int elem_max_freq = 1;
                
                if(elem == '?'){
                    elem_min_freq = 1;
                    elem_max_freq = 1;
                }else if(elem == '*'){
                    elem_min_freq = 0;
                    int remaining_letters = count_if(p.begin() + p_idx, p.end(), is_letter);
                    elem_max_freq = (int)s.length() - remaining_letters - s_idx;
                }
                
                if(s_idx + elem_max_freq <= s.length()){
                    for(int elem_freq = elem_min_freq; !is_match && elem_freq <= elem_max_freq; ++elem_freq){
                        back(s_idx + elem_freq, p_idx + 1);
                    }
                }
            }
        }
    }
    
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->is_match = false;
        
        if(prefix_match() && suffix_match() && s_contains_all_letter_sequences_from_p()){
            remove_consecutive_wildcards();
            back(0, 0);
        }
        
        return is_match;
    }
};