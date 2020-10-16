class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int rightSum = 0;
        int answer = leftSum;
        for(int i = k - 1, j = (int)cardPoints.size() - 1; i >= 0; --i, --j){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[j];
            answer = max(leftSum + rightSum, answer);
        }
        return answer;
    }
};