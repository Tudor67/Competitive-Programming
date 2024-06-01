class Solution {
private:
    int countCompleteSubstringsHelper(string word, int k){
        const int N = word.length();
        const int A = 26;

        int completeSubstrings = 0;
        vector<int> freq(A);

        for(int targetDistinctChars = 1; targetDistinctChars <= min(A, N); ++targetDistinctChars){
            int goodDistinctChars = 0;
            fill(freq.begin(), freq.end(), 0);

            for(int i = 0; i < N; ++i){
                goodDistinctChars -= (int)(freq[word[i] - 'a'] == k);
                freq[word[i] - 'a'] += 1;
                goodDistinctChars += (int)(freq[word[i] - 'a'] == k);

                if(i >= k * targetDistinctChars){
                    int j = i - k * targetDistinctChars;
                    goodDistinctChars -= (int)(freq[word[j] - 'a'] == k);
                    freq[word[j] - 'a'] -= 1;
                    goodDistinctChars += (int)(freq[word[j] - 'a'] == k);
                }

                if(goodDistinctChars == targetDistinctChars){
                    completeSubstrings += 1;
                }
            }
        }

        return completeSubstrings;
    }

public:
    int countCompleteSubstrings(string word, int k) {
        const int N = word.length();

        int completeSubstrings = 0;
        int i = 0;
        while(i < N){
            int j = i + 1;
            while(abs(word[j - 1] - word[j]) <= 2){
                j += 1;
            }
            completeSubstrings += countCompleteSubstringsHelper(word.substr(i, j - i), k);
            i = j;
        }

        return completeSubstrings;
    }
};