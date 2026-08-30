class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();

        vector<int> maxSuffixMatch(N1 + 1);
        for(int i1 = N1 - 1, i2 = N2 - 1; i1 >= 0; --i1){
            if(i2 >= 0 && word1[i1] == word2[i2]){
                --i2;
            }
            maxSuffixMatch[i1] = N2 - 1 - i2;
        }

        vector<int> res;
        bool changed = false;
        for(int i1 = 0; i1 < N1 && (int)res.size() < N2; ++i1){
            if(word1[i1] == word2[res.size()]){
                res.push_back(i1);
            }else if(!changed && (int)res.size() + 1 + maxSuffixMatch[i1 + 1] >= N2){
                changed = true;
                res.push_back(i1);
            }
        }

        if((int)res.size() == N2){
            return res;
        }

        return {};
    }
};