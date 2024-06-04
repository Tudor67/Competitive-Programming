class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        const int N = word.length();

        int minCost = 0;
        int i = 1;
        while(i < N){
            if(abs(word[i - 1] - word[i]) <= 1){
                minCost += 1;
                i += 2;
            }else{
                i += 1;
            }
        }

        return minCost;
    }
};