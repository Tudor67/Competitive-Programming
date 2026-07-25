class Solution {
public:
    string smallestSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> remFreq(A);
        for(char c: s){
            remFreq[c - 'a'] += 1;
        }

        string res;
        vector<bool> inRes(A);
        for(char c: s){
            remFreq[c - 'a'] -= 1;
            if(!inRes[c - 'a']){
                while(!res.empty() && res.back() > c && remFreq[res.back() - 'a'] > 0){
                    inRes[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                inRes[c - 'a'] = true;
            }
        }

        return res;
    }
};