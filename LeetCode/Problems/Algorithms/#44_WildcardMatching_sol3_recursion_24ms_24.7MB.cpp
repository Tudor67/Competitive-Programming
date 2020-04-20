class Solution {
private:
    bool is_match(string s, string p) {
        if(s.empty()){
            // --- Case 1: s is empty ---
            bool match_empty_seq = true;
            for(char c: p){
                match_empty_seq = (match_empty_seq && (c == '*'));
            }
            return match_empty_seq;
        }else{
            // --- Case 2: s is not empty ---
            if(p.empty()){
                return false;
            }else{
                bool match_char = (s[0] == p[0] || p[0] == '?');
                bool match_seq = (p[0] == '*');

                if(match_char){
                    return is_match(s.substr(1), p.substr(1));
                }else if(match_seq){
                    return (is_match(s, p.substr(1)) || is_match(s.substr(1), p) || is_match(s.substr(1), p.substr(1)));
                }else{
                    return false;
                }
            }
        }
    }
    
    void remove_consecutive_wildcards(string& p){
        string st;
        for(char c: p){
            if(c == '*' && !st.empty() && st.back() == '*'){
                st.pop_back();
            }
            st.push_back(c);
        }
        p = st;
    }
    
    bool s_contains_all_letter_sequences_from_p(const string& s, const string& p){
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
    
    bool prefix_match(const string& s, const string& p){
        for(int i = 0; i < min(s.length(), p.length()); ++i){
            if(s[i] != p[i] && p[i] != '?'){
                return (p[i] == '*');
            }
        }
        return true;
    }
    
    bool suffix_match(const string& s, const string& p){
        for(int i = (int)s.length() - 1, j = (int)p.length() - 1; i >= 0 && j >= 0; --i, --j){
            if(s[i] != p[j] && p[j] != '?'){
                return (p[j] == '*');
            }
        }
        return true;
    }
    
public:
    bool isMatch(string s, string p) {
        remove_consecutive_wildcards(p);
        return s_contains_all_letter_sequences_from_p(s, p) &&
               prefix_match(s, p) &&
               suffix_match(s, p) &&
               is_match(s, p);
    }
};