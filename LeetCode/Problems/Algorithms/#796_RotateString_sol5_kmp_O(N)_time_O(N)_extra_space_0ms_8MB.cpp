class Solution {
private:
    bool isSubstring(string p, string s){
        string ps = p + "$" + s;
        
        vector<int> lps(ps.length());
        for(int i = 1; i < (int)ps.length(); ++i){
            int k = lps[i - 1];
            while(k > 0 && ps[k] != ps[i]){
                k = lps[k - 1];
            }
            if(ps[k] == ps[i]){
                k += 1;
            }
            lps[i] = k;
        }

        return (*max_element(lps.begin(), lps.end()) == (int)p.length());
    }

public:
    bool rotateString(string s, string goal) {
        return (s.length() == goal.length() && isSubstring(s, goal + goal));
    }
};