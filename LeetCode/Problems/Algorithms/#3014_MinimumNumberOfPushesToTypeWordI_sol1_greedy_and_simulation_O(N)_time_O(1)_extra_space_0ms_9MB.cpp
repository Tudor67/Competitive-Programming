class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();

        int totalCost = 0;
        for(int i = 0; i < N; ++i){
            totalCost += (i / 8) + 1;
        }

        return totalCost;
    }
};