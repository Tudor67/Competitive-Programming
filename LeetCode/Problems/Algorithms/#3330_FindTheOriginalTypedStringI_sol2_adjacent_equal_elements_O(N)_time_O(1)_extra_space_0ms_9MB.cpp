class Solution {
public:
    int possibleStringCount(string word) {
        const int N = word.length();

        int res = 1;
        for(int i = 1; i < N; ++i){
            if(word[i - 1] == word[i]){
                res += 1;
            }
        }
        
        return res;
    }
};