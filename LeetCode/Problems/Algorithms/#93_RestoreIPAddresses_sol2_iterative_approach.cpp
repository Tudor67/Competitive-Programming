class Solution {
private:
    bool is_valid(const string& s){
        bool has_leading_zeros = (s.length() > 1 && s[0] == '0');
        bool is_less_than_256 = (s.length() == 3 ? (s < "256") : s.length() < 3);
        return !has_leading_zeros && is_less_than_256;
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for(int i = 1; i <= 3; ++i){
            for(int j = 1; j <= 3; ++j){
                for(int k = 1; k <= 3; ++k){
                    for(int l = 1; l <= 3; ++l){
                        if(i + j + k + l == s.length()){
                            string a = s.substr(0, i);
                            string b = s.substr(i, j);
                            string c = s.substr(i + j, k);
                            string d = s.substr(i + j + k, l);
                            if(is_valid(a) && is_valid(b) && is_valid(c) && is_valid(d)){
                                ans.push_back(a + "." + b + "." + c + "." + d);
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};