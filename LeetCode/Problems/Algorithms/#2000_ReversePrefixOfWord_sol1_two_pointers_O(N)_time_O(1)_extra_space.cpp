class Solution {
public:
    string reversePrefix(string word, char ch) {
        const int N = word.length();
        
        int j = 0;
        while(j < N && word[j] != ch){
            ++j;
        }
        
        if(j < N){
            int i = 0;
            while(i < j){
                swap(word[i], word[j]);
                ++i;
                --j;
            }
        }
        
        return word;
    }
};