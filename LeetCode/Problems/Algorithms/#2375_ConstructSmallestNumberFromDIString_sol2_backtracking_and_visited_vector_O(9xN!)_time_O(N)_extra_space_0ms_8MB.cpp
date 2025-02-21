class Solution {
private:
    void search(int index, vector<bool>& vis, string& st, string& pattern, string& res){
        if(!res.empty()){
            // stop
        }else if(index == (int)pattern.length()){
            res = st;
        }else{
            for(char c = '1'; c <= '9'; ++c){
                if(!vis[c - '0']){
                    if((pattern[index] == 'I' && st.back() < c) ||
                       (pattern[index] == 'D' && st.back() > c)){
                        st.push_back(c);
                        vis[c - '0'] = true;
                        search(index + 1, vis, st, pattern, res);
                        vis[c - '0'] = false;
                        st.pop_back();
                    }
                }
            }
        }
    }

public:
    string smallestNumber(string pattern) {
        string res;
        vector<bool> vis(10, false);
        for(char startChar = '1'; startChar <= '9' && res.empty(); ++startChar){
            string st(1, startChar);
            vis[startChar - '0'] = true;
            search(0, vis, st, pattern, res);
            vis[startChar - '0'] = false;
        }
        return res;
    }
};