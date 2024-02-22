class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int N = s1.length();

        vector<unordered_map<char, int>> balance(2);
        for(int i = 0; i < N; ++i){
            balance[i % 2][s1[i]] += 1;
            balance[i % 2][s2[i]] -= 1;
        }

        for(int parity = 0; parity <= 1; ++parity){
            for(const pair<const int, int>& P: balance[parity]){
                if(P.second != 0){
                    return false;
                }
            }
        }

        return true;
    }
};