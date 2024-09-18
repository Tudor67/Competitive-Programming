class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        const int N = word.length();

        for(int i = k; i < N; i += k){
            if(equal(word.begin() + i, word.end(), word.begin())){
                return i / k;
            }
        }

        return (N + k - 1) / k;
    }
};