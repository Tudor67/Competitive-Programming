class Solution {
public:
    int possibleStringCount(string word) {
        const int N = word.length();

        int res = 1;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && word[l] == word[r]){
                r += 1;
            }
            res += (r - l - 1);
            l = r;
        }

        return res;
    }
};