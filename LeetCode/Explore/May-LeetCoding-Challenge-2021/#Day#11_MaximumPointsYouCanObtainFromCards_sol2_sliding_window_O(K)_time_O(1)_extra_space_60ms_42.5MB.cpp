class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int N = cardPoints.size();
        
        int sum = 0;
        for(int i = 0; i < k; ++i){
            sum += cardPoints[i];
        }
        
        int answer = sum;
        for(int j = 1; j <= k; ++j){
            sum -= cardPoints[k - j];
            sum += cardPoints[N - j];
            answer = max(sum, answer);
        }
        
        return answer;
    }
};