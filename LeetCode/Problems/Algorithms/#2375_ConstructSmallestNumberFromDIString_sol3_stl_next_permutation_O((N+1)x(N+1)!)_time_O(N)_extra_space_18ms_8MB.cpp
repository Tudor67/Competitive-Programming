class Solution {
private:
    bool isValid(string& p, string& pattern){
        for(int i = 0; i < (int)pattern.length(); ++i){
            if((pattern[i] == 'I' && p[i] >= p[i + 1]) ||
               (pattern[i] == 'D' && p[i] <= p[i + 1])){
                return false;
            }
        }
        return true;
    }

public:
    string smallestNumber(string pattern) {
        const int N = pattern.length();

        string p(N + 1, '1');
        iota(p.begin(), p.end(), '1');
        while(!isValid(p, pattern)){
            next_permutation(p.begin(), p.end());
        }

        return p;
    }
};