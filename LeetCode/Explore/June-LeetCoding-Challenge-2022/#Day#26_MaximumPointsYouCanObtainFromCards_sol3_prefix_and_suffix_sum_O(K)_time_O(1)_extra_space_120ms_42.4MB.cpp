class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int N = cardPoints.size();
        
        int prefSum = 0;
        int suffSum = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int maxSum = prefSum + suffSum;
        for(int i = 0; i < k; ++i){
            prefSum += cardPoints[i];
            suffSum -= cardPoints[N - k + i];
            maxSum = max(maxSum, prefSum + suffSum);
        }
        
        return maxSum;
    }
};