class Solution {
private:
    void search(int index, int visMask, string& st, string& pattern, string& res){
        if(!res.empty()){
            // stop
        }else if(index == (int)pattern.length()){
            res = st;
        }else{
            for(char c = '1'; c <= '9'; ++c){
                if(((visMask >> (c - '0')) & 1) == 0){
                    if((pattern[index] == 'I' && st.back() < c) ||
                       (pattern[index] == 'D' && st.back() > c)){
                        st.push_back(c);
                        search(index + 1, visMask | (1 << (c - '0')), st, pattern, res);
                        st.pop_back();
                    }
                }
            }
        }
    }

public:
    string smallestNumber(string pattern) {
        string res;
        for(char startChar = '1'; startChar <= '9' && res.empty(); ++startChar){
            string st(1, startChar);
            search(0, 1 << (startChar - '0'), st, pattern, res);
        }
        return res;
    }
};