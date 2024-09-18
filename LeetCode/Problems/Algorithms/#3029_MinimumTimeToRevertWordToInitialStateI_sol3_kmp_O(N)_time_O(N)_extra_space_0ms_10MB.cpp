class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        const int N = word.length();

        vector<int> lps(N);
        for(int i = 1; i < N; ++i){
            int j = lps[i - 1];
            while(j > 0 && word[j] != word[i]){
                j = lps[j - 1];
            }
            if(word[j] == word[i]){
                j += 1;
            }
            lps[i] = j;
        }

        for(int j = lps[N - 1]; j > 0; j = lps[j - 1]){
            if((N - j) % k == 0){
                return (N - j) / k;
            }
        }

        return (N + k - 1) / k;
    }
};