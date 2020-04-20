class Solution {
private:
    bool is_match(const string& s, int s_idx, const string& p, int p_idx){
        if(p_idx == p.length()){
            return (s_idx == s.length());
        }
        
        bool first_match = (s_idx < s.length() && (p[p_idx] == s[s_idx] || p[p_idx] == '.'));
        
        if(p_idx + 1 < p.length() && p[p_idx + 1] == '*'){
            return (is_match(s, s_idx, p, p_idx + 2)) ||
                   (first_match && is_match(s, s_idx + 1, p, p_idx));
        }else{
            return first_match && is_match(s, s_idx + 1, p, p_idx + 1);
        }
    }
    
public:
    bool isMatch(string s, string p) {
        return is_match(s, 0, p, 0);
    }
};