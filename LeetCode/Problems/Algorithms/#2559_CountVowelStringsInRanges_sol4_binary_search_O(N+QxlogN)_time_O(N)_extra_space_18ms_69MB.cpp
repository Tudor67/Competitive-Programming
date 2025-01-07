class Solution {
private:
    const unordered_set<char> VOWELS_SET = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c){
        return (VOWELS_SET.find(c) != VOWELS_SET.end());
    }

    bool isGoodWord(const string& WORD){
        return (isVowel(WORD.front()) && isVowel(WORD.back()));
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int N = words.size();
        const int Q = queries.size();

        vector<int> goodIndices;
        for(int i = 0; i < N; ++i){
            if(isGoodWord(words[i])){
                goodIndices.push_back(i);
            }
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = upper_bound(goodIndices.begin(), goodIndices.end(), r) -
                     lower_bound(goodIndices.begin(), goodIndices.end(), l);
        }

        return res;
    }
};