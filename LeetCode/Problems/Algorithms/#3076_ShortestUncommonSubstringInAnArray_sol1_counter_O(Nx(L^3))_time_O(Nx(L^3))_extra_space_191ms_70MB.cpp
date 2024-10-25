class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        const int N = arr.size();
        
        unordered_map<string, int> freq;
        for(string& s: arr){
            int sLen = s.length();
            for(int i = 0; i < sLen; ++i){
                for(int j = i; j < sLen; ++j){
                    freq[s.substr(i, j - i + 1)] += 1;
                }
            }
        }
        
        vector<string> res;
        res.reserve(N);

        for(string& s: arr){
            res.push_back("");
            int sLen = s.length();
            for(int i = 0; i < sLen; ++i){
                for(int j = i; j < sLen; ++j){
                    string substr = s.substr(i, j - i + 1);
                    freq[substr] -= 1;
                    if(freq[substr] == 0){
                        if((res.back().empty()) ||
                           (res.back().length() > substr.length()) ||
                           (res.back().length() == substr.length() && res.back() > substr)){
                            res.back() = substr;
                        }
                    }
                }
            }
            
            for(int i = 0; i < sLen; ++i){
                for(int j = i; j < sLen; ++j){
                    freq[s.substr(i, j - i + 1)] += 1;
                }
            }
        }
        
        return res;
    }
};