class Solution {
private:
    void back(int k, int pos, vector<string>& st, const string& s, vector<string>& ans){
        if(k == st.size()){
            if(pos == s.length()){
                string ip = st[0];
                for(int i = 1; i < st.size(); ++i){
                    ip += "." + st[i];
                }
                ans.push_back(ip);
            }
        }else{
            for(int i = pos; i <= min(pos + 2, (int)s.length() - 1); ++i){
                string seq = s.substr(pos, i - pos + 1);
                bool has_leading_zeros = (seq.length() > 1 && seq[0] == '0');
                bool is_less_than_256 = (seq.length() == 3 ? (seq < "256") : seq.size() < 3);
                if(!has_leading_zeros && is_less_than_256){
                    st[k] = seq;
                    back(k + 1, i + 1, st, s, ans);
                }
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> st(4);
        back(0, 0, st, s, ans);
        return ans;
    }
};