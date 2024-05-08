class Solution {
public:
    string reversePrefix(string word, char ch) {
        const int N = word.size();
        
        for(int i = 0; i < N; ++i){
            if(word[i] == ch){
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }

        return word;
    }
};