class Solution {
public:
    int minSteps(string s, string t) {
        const int N = s.length();

        unordered_map<char, int> balance;
        for(int i = 0; i < N; ++i){
            balance[s[i]] += 1;
            balance[t[i]] -= 1;
        }

        int minOps = 0;
        for(pair<const char, int>& P: balance){
            int charBalance = P.second;
            if(charBalance > 0){
                minOps += charBalance;
            }
        }

        return minOps;
    }
};