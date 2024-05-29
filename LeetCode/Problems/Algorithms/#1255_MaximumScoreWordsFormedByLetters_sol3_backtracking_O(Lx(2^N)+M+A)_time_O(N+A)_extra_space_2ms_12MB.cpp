class Solution {
private:
    const int A = 26;
    const char MIN_CHAR = 'a';

    void back(int i, int currScore, int& maxScore, vector<int>& remFreq,
              vector<string>& words, vector<int>& score){
        if(i == (int)words.size()){
            maxScore = max(maxScore, currScore);
        }else{
            // skip
            back(i + 1, currScore, maxScore, remFreq, words, score);

            // take
            bool isValid = true;
            int contrib = 0;
            for(char c: words[i]){
                contrib += score[c - MIN_CHAR];
                remFreq[c - MIN_CHAR] -= 1;
                if(remFreq[c - MIN_CHAR] < 0){
                    isValid = false;
                }
            }

            if(isValid){
                back(i + 1, currScore + contrib, maxScore, remFreq, words, score);
            }

            for(char c: words[i]){
                remFreq[c - MIN_CHAR] += 1;
            }
        }
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        const int N = words.size();

        vector<int> maxFreq(A);
        for(char c: letters){
            maxFreq[c - MIN_CHAR] += 1;
        }

        int maxScore = 0;
        back(0, 0, maxScore, maxFreq, words, score);

        return maxScore;
    }
};