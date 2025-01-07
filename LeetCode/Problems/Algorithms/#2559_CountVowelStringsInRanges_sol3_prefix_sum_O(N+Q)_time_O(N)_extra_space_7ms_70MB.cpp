class Solution {
private:
    const unordered_set<char> VOWELS_SET = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c){
        return (VOWELS_SET.find(c) != VOWELS_SET.end());
    }

    bool isGoodWord(const string& WORD){
        return (isVowel(WORD.front()) && isVowel(WORD.back()));
    }

    int computeRangeSum(vector<int>& prefSum, int l, int r){
        if(l > r) return 0;
        if(l == 0) return prefSum[r];
        return (prefSum[r] - prefSum[l - 1]);
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int N = words.size();
        const int Q = queries.size();

        vector<int> prefSum(N);
        prefSum[0] = isGoodWord(words[0]);
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + isGoodWord(words[i]);
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = computeRangeSum(prefSum, l, r);
        }

        return res;
    }
};