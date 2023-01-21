class Solution {
private:
    bool isValid(const string& NUM_STR){
        return (stoi(NUM_STR) <= 255) && ((int)NUM_STR.length() == 1 || NUM_STR[0] != '0');
    }

public:
    vector<string> restoreIpAddresses(string s) {
        const int N = s.length();

        if(N > 12){
            return {};
        }

        vector<string> res;
        for(int i = 1; i <= 3; ++i){
            for(int j = 1; j <= 3; ++j){
                for(int k = 1; k <= 3; ++k){
                    for(int l = 1; l <= 3; ++l){
                        if(i + j + k + l == N){
                            string a = s.substr(0, i);
                            string b = s.substr(i, j);
                            string c = s.substr(i + j, k);
                            string d = s.substr(i + j + k, l);
                            if(isValid(a) && isValid(b) && isValid(c) && isValid(d)){
                                res.push_back(a + "." + b + "." + c + "." + d);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};