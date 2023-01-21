class Solution {
private:
    void back(int level, int startPos, const string& S, vector<string>& st, vector<string>& res){
        if(level == (int)st.size()){
            if(startPos == (int)S.length()){
                string ip = st[0];
                for(int i = 1; i < (int)st.size(); ++i){
                    ip += ".";
                    ip += st[i];
                }
                res.push_back(ip);
            }
        }else{
            for(int len = 1; len <= 3 && startPos + len - 1 < (int)S.length(); ++len){
                string numStr = S.substr(startPos, len);
                if(stoi(numStr) <= 255 && (len == 1 || numStr[0] != '0')){
                    st[level] = numStr;
                    back(level + 1, startPos + len, S, st, res);
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        const int N = s.length();

        if(N > 12){
            return {};
        }

        vector<string> st(4);
        vector<string> res;
        back(0, 0, s, st, res);

        return res;
    }
};