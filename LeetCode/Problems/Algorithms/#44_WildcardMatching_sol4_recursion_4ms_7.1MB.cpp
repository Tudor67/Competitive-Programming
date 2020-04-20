class Solution {
private:
    string s;
    string p;
    
    void remove_consecutive_wildcards(){
        string st;
        for(char c: p){
            if(c == '*' && !st.empty() && st.back() == '*'){
                st.pop_back();
            }
            st.push_back(c);
        }
        p = st;
    }
    
    bool s_contains_all_letter_sequences_from_p(){
        int pos = 0;
        string seq = "";
        for(int i = 0; i < p.length(); ++i){
            if(p[i] != '*' && p[i] != '?'){
                seq += p[i];
            }
            
            if(!seq.empty() && (p[i] == '*' || p[i] == '?' || i == (int)p.length() - 1)){
                pos = s.find(seq, pos);
                if(pos == string::npos){
                    return false;
                }
                pos += seq.length();
                seq = "";
            }
        }
        return true;
    }
    
    bool prefix_match(){
        for(int i = 0; i < min(s.length(), p.length()); ++i){
            if(s[i] != p[i] && p[i] != '?'){
                return (p[i] == '*');
            }
        }
        return true;
    }
    
    bool suffix_match(){
        for(int i = (int)s.length() - 1, j = (int)p.length() - 1; i >= 0 && j >= 0; --i, --j){
            if(s[i] != p[j] && p[j] != '?'){
                return (p[j] == '*');
            }
        }
        return true;
    }

    bool is_match(int s_idx, int p_idx) {
        if(s_idx == s.length()){
            // --- Case 1: s is empty ---
            bool match_empty_seq = true;
            for(int i = p_idx; i < p.length(); ++i){
                char c = p[i];
                match_empty_seq = (match_empty_seq && (c == '*'));
            }
            return match_empty_seq;
        }else{
            // --- Case 2: s is not empty ---
            if(p_idx == p.length()){
                return false;
            }else{
                bool match_char = (s[s_idx] == p[p_idx] || p[p_idx] == '?');
                bool match_seq = (p[p_idx] == '*');

                if(match_char){
                    return is_match(s_idx + 1, p_idx + 1);
                }else if(match_seq){
                    return (is_match(s_idx, p_idx + 1) || is_match(s_idx + 1, p_idx) || is_match(s_idx + 1, p_idx + 1));
                }else{
                    return false;
                }
            }
        }
    }
    
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        remove_consecutive_wildcards();
        return s_contains_all_letter_sequences_from_p() &&
               prefix_match() &&
               suffix_match() &&
               is_match(0, 0);
    }
};