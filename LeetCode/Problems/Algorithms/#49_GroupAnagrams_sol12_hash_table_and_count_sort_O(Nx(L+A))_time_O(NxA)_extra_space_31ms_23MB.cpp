class Solution {
private:
    const int A = 26;
    vector<int> freq;

    string computeCanonicalForm(const string& S){
        const int L = S.length();

        freq.resize(A);
        fill(freq.begin(), freq.end(), 0);

        for(char c: S){
            freq[c - 'a'] += 1;
        }

        string canonicalForm;
        for(char c = 'a'; c <= 'z'; ++c){
            if(freq[c - 'a'] >= 1){
                canonicalForm += c;
                canonicalForm += to_string(freq[c - 'a']);
            }
        }

        return canonicalForm;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();

        unordered_map<string, vector<int>> canonicalFormToIndices;
        for(int i = 0; i < N; ++i){
            canonicalFormToIndices[computeCanonicalForm(strs[i])].push_back(i);
        }

        vector<vector<string>> res;
        res.reserve(canonicalFormToIndices.size());
        for(const pair<const string, vector<int>>& P: canonicalFormToIndices){
            const vector<int>& INDICES = P.second;
            res.push_back({});
            for(int i: INDICES){
                res.back().push_back(strs[i]);
            }
        }

        return res;
    }
};