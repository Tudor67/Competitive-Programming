class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();

        int totalCost = 0;
        for(int i = 0; i < N; ++i){
            totalCost += (1 + i / 8);
        }

        return totalCost;
    }
};