class Solution {
private:
    vector<int> lexSmallestSubseq(const string& S1, const int SPECIAL_IDX, const string& S2){
        const int N1 = S1.length();
        const int N2 = S2.length();

        vector<int> indices;
        indices.reserve(N2);

        for(int i1 = 0, i2 = 0; i1 < N1 && i2 < N2; ++i1){
            if(i1 == SPECIAL_IDX || S1[i1] == S2[i2]){
                indices.push_back(i1);
                ++i2;
            }
        }

        if((int)indices.size() == N2){
            return indices;
        }

        return {};
    }

public:
    vector<int> validSequence(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();

        vector<int> maxPrefixMatch(N1);
        for(int i1 = 0, i2 = 0; i1 < N1; ++i1){
            if(i2 < N2 && word1[i1] == word2[i2]){
                ++i2;
            }
            maxPrefixMatch[i1] = i2;
        }

        vector<int> maxSuffixMatch(N1);
        for(int i1 = N1 - 1, i2 = N2 - 1; i1 >= 0; --i1){
            if(i2 >= 0 && word1[i1] == word2[i2]){
                --i2;
            }
            maxSuffixMatch[i1] = N2 - 1 - i2;
        }

        for(int i = 0; i < N1; ++i){
            int pref = (i - 1 >= 0 ? maxPrefixMatch[i - 1] : 0);
            int suff = (i + 1 < N1 ? maxSuffixMatch[i + 1] : 0);
            if(pref + 1 + suff >= N2 && pref < N2 && word1[i] != word2[pref]){
                return lexSmallestSubseq(word1, i, word2);
            }
        }

        return lexSmallestSubseq(word1, -1, word2);
    }
};