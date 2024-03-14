class Solution {
public:
    string customSortString(string order, string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            freq[c - 'a'] += 1;
        }

        string res;
        res.reserve(N);
        for(char c: order){
            res.append(freq[c - 'a'], c);
            freq[c - 'a'] = 0;
        }

        for(char c = 'a'; c <= 'z'; ++c){
            res.append(freq[c - 'a'], c);
        }

        return res;
    }
};