class Solution {
public:
    string answerString(string word, int numFriends) {
        const int N = word.length();
        const int MAX_LEN = N - numFriends + 1;

        if(numFriends == 1){
            return word;
        }

        int resStartIndex = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < MAX_LEN && i + j < N; ++j){
                if(word[i + j] < word[resStartIndex + j]){
                    break;
                }else if(word[i + j] > word[resStartIndex + j]){
                    resStartIndex = i;
                    break;
                }
            }
        }

        return word.substr(resStartIndex, MAX_LEN);
    }
};