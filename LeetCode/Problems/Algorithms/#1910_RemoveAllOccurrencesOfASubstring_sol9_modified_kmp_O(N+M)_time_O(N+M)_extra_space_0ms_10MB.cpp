class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ps = part + "$" + s;

        string res;
        vector<int> lps = {0};
        for(int i = 1; i < (int)ps.length(); ++i){
            if(i > part.length()){
                res.push_back(ps[i]);
            }
            
            int k = lps.back();
            while(k > 0 && ps[k] != ps[i]){
                k = lps[k - 1];
            }
            if(ps[k] == ps[i]){
                k += 1;
            }
            lps.push_back(k);

            if(lps.back() == (int)part.length()){
                for(int j = 0; j < (int)part.length(); ++j){
                    res.pop_back();
                    lps.pop_back();
                }
            }
        }

        return res;
    }
};