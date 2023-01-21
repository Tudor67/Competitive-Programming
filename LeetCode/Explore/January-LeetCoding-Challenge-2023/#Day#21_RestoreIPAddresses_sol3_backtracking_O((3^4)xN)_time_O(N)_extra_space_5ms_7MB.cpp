class Solution {
private:
    void back(int level, int startPos, const string& S, string& ip, vector<string>& res){
        if(level == 4){
            if(startPos == (int)S.length()){
                res.push_back(ip);
                res.back().pop_back();
            }
        }else{
            for(int len = 1; len <= 3 && startPos + len - 1 < (int)S.length(); ++len){
                string numStr = S.substr(startPos, len);
                int num = stoi(numStr);
                if(num <= 255 && (len == 1 || numStr[0] != '0')){
                    ip += numStr;
                    ip += ".";
                    back(level + 1, startPos + len, S, ip, res);
                    ip.erase(ip.end() - len - 1, ip.end());
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

        string ip;
        vector<string> res;
        back(0, 0, s, ip, res);

        return res;
    }
};