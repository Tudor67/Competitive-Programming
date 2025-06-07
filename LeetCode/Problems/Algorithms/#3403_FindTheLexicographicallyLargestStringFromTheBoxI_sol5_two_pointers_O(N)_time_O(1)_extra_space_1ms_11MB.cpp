class Solution {
public:
    string answerString(string word, int numFriends) {
        const int N = word.length();
        const int MAX_LEN = N - numFriends + 1;

        if(numFriends == 1){
            return word;
        }

        int i = 0;
        int j = 1;
        while(j < N){
            int k = 0;
            while(j + k < N && word[i + k] == word[j + k]){
                k += 1;
            }

            if(j + k < N && word[i + k] < word[j + k]){
                int oldI = i;
                i = j;
                j = max(j + 1, oldI + k + 1);
            }else{
                j = j + k + 1;
            }
        }

        return word.substr(i, MAX_LEN);
    }
};