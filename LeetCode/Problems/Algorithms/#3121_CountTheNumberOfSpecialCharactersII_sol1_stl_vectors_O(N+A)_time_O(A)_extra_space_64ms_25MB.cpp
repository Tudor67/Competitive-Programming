class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int N = word.length();
        const int A = 26;
        const int INF = 1e9;

        vector<int> maxIndexOfLower(A, -INF);
        vector<int> minIndexOfUpper(A, INF);
        for(int i = 0; i < N; ++i){
            char c = word[i];
            if(islower(c)){
                maxIndexOfLower[c - 'a'] = i;
            }else{
                minIndexOfUpper[c - 'A'] = min(minIndexOfUpper[c - 'A'], i);
            }
        }

        int specialLetters = 0;
        for(int i = 0; i < A; ++i){
            if(maxIndexOfLower[i] != -INF &&
               minIndexOfUpper[i] != INF &&
               maxIndexOfLower[i] < minIndexOfUpper[i]){
                ++specialLetters;
            }
        }

        return specialLetters;
    }
};