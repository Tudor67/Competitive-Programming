class Solution {
public:
    int addMinimum(string word) {
        const int N = word.length();
        
        int res = 0;
        
        int i = 0;
        while(i < N){
            int j = i;
            while(j + 1 < N && word[j] < word[j + 1]){
                j += 1;
            }
            int len = j - i + 1;
            res += 3 - len;
            i += len;
        }
        
        return res;
    }
};