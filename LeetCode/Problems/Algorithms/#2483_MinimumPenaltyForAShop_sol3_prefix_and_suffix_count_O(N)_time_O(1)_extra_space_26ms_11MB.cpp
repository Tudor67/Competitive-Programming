class Solution {
public:
    int bestClosingTime(string customers) {
        const int N = customers.length();

        int prefN = 0;
        int suffY = count(customers.begin(), customers.end(), 'Y');

        int minPenalty = prefN + suffY;
        int minPenaltyIndex = 0;
        for(int i = 0; i < N; ++i){
            prefN += (int)(customers[i] == 'N');
            suffY -= (int)(customers[i] == 'Y');
            if(prefN + suffY < minPenalty){
                minPenalty = prefN + suffY;
                minPenaltyIndex = i + 1;
            }
        }

        return minPenaltyIndex;
    }
};