class Solution {
public:
    bool isCircularSentence(string sentence) {
        const int N = sentence.length();

        for(int i = 0; i < N; ++i){
            if(sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]){
                return false;
            }
        }
        
        return (sentence.front() == sentence.back());
    }
};