class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        const int N = words.size();
        const int FULL_MASK = (1 << N) - 1;
        const int A = 26;
        const char MIN_CHAR = 'a';

        vector<int> maxFreq(A);
        for(char c: letters){
            maxFreq[c - MIN_CHAR] += 1;
        }

        int maxScore = 0;
        vector<int> currFreq(A);
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isValid = true;
            int currScore = 0;
            fill(currFreq.begin(), currFreq.end(), 0);

            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    for(char c: words[bit]){
                        currScore += score[c - MIN_CHAR];
                        currFreq[c - MIN_CHAR] += 1;
                        if(currFreq[c - MIN_CHAR] > maxFreq[c - MIN_CHAR]){
                            isValid = false;
                        }
                    }
                }
            }

            if(isValid){
                maxScore = max(maxScore, currScore);
            }
        }

        return maxScore;
    }
};