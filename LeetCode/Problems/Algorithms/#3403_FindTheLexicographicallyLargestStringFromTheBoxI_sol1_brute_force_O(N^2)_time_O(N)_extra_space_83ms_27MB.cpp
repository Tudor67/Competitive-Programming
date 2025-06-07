class Solution {
public:
    string answerString(string word, int numFriends) {
        const int N = word.length();
        const int MAX_LEN = N - numFriends + 1;

        if(numFriends == 1){
            return word;
        }

        string res = word.substr(0, MAX_LEN);

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < MAX_LEN && i + j < N; ++j){
                if(word[i + j] < res[j]){
                    break;
                }else if(word[i + j] > res[j]){
                    res = word.substr(i, MAX_LEN);
                    break;
                }
            }
        }

        return res;
    }
};