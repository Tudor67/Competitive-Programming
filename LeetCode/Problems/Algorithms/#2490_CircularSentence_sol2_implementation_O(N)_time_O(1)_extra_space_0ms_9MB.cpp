class Solution {
public:
    bool isCircularSentence(string sentence) {
        const int N = sentence.length();

        char lastChar = sentence.back();
        for(int i = 0; i < N; ++i){
            if(i >= 2 && sentence[i - 1] == ' '){
                lastChar = sentence[i - 2];
            }
            if(i == 0 || sentence[i - 1] == ' '){
                if(lastChar != sentence[i]){
                    return false;
                }
            }
        }

        return true;
    }
};