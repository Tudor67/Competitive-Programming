class Solution {
public:
    int bestClosingTime(string customers) {
        const int N = customers.length();
        
        int prefCountN = 0;
        int suffCountY = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = suffCountY;
        int minTime = 0;
        for(int i = 0; i <= N; ++i){
            int penalty = prefCountN + suffCountY;
            if(penalty < minPenalty){
                minPenalty = penalty;
                minTime = i;
            }
            prefCountN += (i < N && customers[i] == 'N');
            suffCountY -= (i < N && customers[i] == 'Y');
        }
        
        return minTime;
    }
};